
#include "ques1.h"
template <typename T>
class comp
{
    public:
    T real;
    T img;

    comp()
    {
        real=0, img=0;
    }

    comp(T x, T y)
    {
        real=x;
        img=y;
    }

    void display()
    {
        cout<<real<<" + "<<img<<"j"<<endl;
    }

    comp<T> operator +(comp<T> c)
    {
        comp<T> res;
        res.real = real + c.real;
        res.img = img + c.img;
        return res;
    }

    comp<T> operator -(comp<T> c)
    {
        comp<T> res;
        res.real = real - c.real;
        res.img = img - c.img;
        return res;
    }

    comp<T> operator *(comp<T> c)
    {
        comp<T> res;
        res.real = real*(c.real) - img*(c.img);
        res.img = (c.real)*img + real*(c.img);
        return res;
    }
};

template <typename T>
class mat
{
    public:
    int rows,cols;
    T** matrix;

    mat(int x, int y)
    {
        rows=x, cols=y;
        matrix = new T*[rows];
        for (int i = 0; i < rows; ++i)
        matrix[i] = new T[cols];
        
        for(int i=0;i<rows;++i)
        for(int j=0;j<cols;++j)
        matrix[i][j]=0;
    }

    void display()
    {
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
    }

    mat<T> transpose()
    {
        mat<T> res(cols,rows);

        for(int i=0;i<rows;++i)
        for(int j=0;j<cols;++j)
        res.matrix[j][i]=matrix[i][j];

        return res;
    } 

    mat<T> operator +(mat<T> m)
    {
        mat<T> res(rows,cols);
        
        if(m.rows!=rows or m.cols!=cols)
        cout<<"Dimensions do not match!!!\n";

        for(int i=0;i<rows;++i)
        for(int j=0;j<cols;++j)
        res.matrix[i][j] = matrix[i][j] + m.matrix[i][j];

        return res;
    }

    mat<T> operator -(mat<T> m)
    {
        mat<T> res(rows,cols);
        
        if(m.rows!=rows or m.cols!=cols)
        cout<<"Dimensions do not match!!!\n";

        for(int i=0;i<rows;++i)
        for(int j=0;j<cols;++j)
        res.matrix[i][j] = matrix[i][j] - m.matrix[i][j];

        return res;
    }

    mat<T> operator *(mat<T> m)
    {
        mat<T> res(rows,m.cols);
        
        if(m.rows!=cols)
        cout<<"Dimensions do not match!!!\n";
        else   
        {
            for(int i=0;i<rows;++i)
            for(int j=0;j<m.cols;++j)
            {
                for(int k=0;k<cols;++k)
                res.matrix[i][j] += matrix[i][k]*(m.matrix[k][j]);
            }
        }

        return res;
    }
};
