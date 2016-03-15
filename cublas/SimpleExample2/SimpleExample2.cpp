#include <algorithm>
#include <iostream>
#include <time.h>
#include <cublas.h>
#include <cublas_v2.h>
#include <stdio.h>
using namespace std;


#define  IDX2C(i,j,leading) (((j)*(leading))+(i))


typedef struct _data *PDATA;
typedef struct _data
{
    int _rows;
    int _cols;
    float *data;
} Data;

void free_mat(PDATA mat)
{
    free(mat->data);
    free(mat);
}

PDATA mat_product(PDATA mat1,PDATA mat2)
{
    if(mat1->_cols!=mat2->_rows)
    {
        printf("this is not right\n");
        return NULL;
    }
    PDATA mat3=new Data;
    mat3->data=(float *)malloc(sizeof(float)*(mat1->_rows)*(mat2->_cols));
    mat3->_rows=mat1->_rows;
    mat3->_cols=mat2->_cols;
    /*
     *INIT the matrix we want calculate
     * col primary
     */
    {
        float *d_a,*d_b,*d_c;
        cublasInit();
        cublasAlloc((mat1->_cols)*(mat1->_rows),sizeof(float),(void **)&d_a);
        cublasAlloc((mat2->_cols)*(mat2->_rows),sizeof(float),(void **)&d_b);
        cublasAlloc((mat3->_rows)*(mat3->_cols),sizeof(float),(void **)&d_c);
        cudaMemcpy(d_a,mat1->data,sizeof(float)*(mat1->_cols)*(mat1->_rows),cudaMemcpyHostToDevice);
        cudaMemcpy(d_b,mat2->data,sizeof(float)*(mat2->_rows)*(mat2->_cols),cudaMemcpyHostToDevice);
        cublasHandle_t handle;
        cublasCreate(&handle);
        float alpha=1.0;
        float beta=0.0;
        cublasSgemm(handle,CUBLAS_OP_N,CUBLAS_OP_N,mat1->_rows,mat2->_cols,
                    mat2->_rows,&alpha,d_a,mat1->_rows,d_b,mat2->_rows,&beta,d_c,mat1->_rows);
        cudaMemcpy(mat3->data,d_c,sizeof(float)*(mat3->_rows)*(mat3->_cols),cudaMemcpyDeviceToHost);
        cublasShutdown();
    }
    /* need to trans the mat3*/
    return mat3;
}

void ele_mat_show(PDATA mat)
{
    for (int i=0;i<mat->_rows;i++){
        for (int j=0;j<mat->_cols;j++){
            cout<<mat->data[IDX2C(i,j,mat->_rows)]<<"\t";
        }
        cout<<endl;
    }
}
float myrand()
{
    return rand()%10;
}
int main()
{
    clock_t start,end;

#if 0
    for (int i=0;i<M*N;i++)
    {
        cout<<c[i]<<"\t";
    }
    cout<<endl;
#endif

    PDATA mat1,mat2,mat3;
    /* remember to initialize the point*/
    mat1=(PDATA)malloc(sizeof(Data));
    mat2=(PDATA)malloc(sizeof(Data));
    mat3=(PDATA)malloc(sizeof(Data));
    mat1->_rows=5;
    mat1->_cols=10;
    mat1->data=(float *)malloc(sizeof(float)*mat1->_rows*mat1->_cols);
    for (int i=0;i<5;i++)
        for (int j=0;j<10;j++)
            mat1->data[IDX2C(i,j,mat1->_rows)]=i*j;
    //generate(mat1->data,mat1->data+(mat1->_cols)*(mat1->_rows),myrand);
    ele_mat_show(mat1);
    mat2->_rows=10;
    mat2->_cols=2;
    mat2->data=(float *)malloc(sizeof(float)*mat2->_rows*mat2->_cols);
    for (int i=0;i<10;i++)
        for (int j=0;j<2;j++)
            mat2->data[IDX2C(i,j,mat2->_rows)]=i*j;
    //generate(mat2->data,mat2->data+(mat2->_cols)*(mat2->_rows),myrand);
    ele_mat_show(mat2);
    mat3=mat_product(mat1,mat2);
    for (int i=0;i<mat3->_rows;i++)
    {
        for (int j=0;j<mat3->_cols;j++)
        {
            cout<<mat3->data[i+j*mat3->_rows]<<'\t';
        }
        cout<<endl;
    }

    return 0;
}

