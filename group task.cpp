#include <iostream>
#include <valarray>
using namespace std;

class Matrix
{
 private:
     int row,col;
     valarray<int>data;

 public:

     Matrix(){
     row=0;
     col=0;

     }

    void createMatrix (int row, int col, int num[], Matrix& mat) {
    mat.row = row;
    mat.col = col;
    mat.data.resize (row * col);
    for (int i = 0; i < row * col; i++)
    mat.data [i] = num [i];
    }

  //-------------------------------------------------------------------Mohamed Khaled Khedr    student 2

     friend istream& operator>> (istream& in, Matrix& mat);
     friend ostream& operator<<(ostream& out, Matrix mat);
     friend Matrix operator+= (Matrix& mat1, Matrix mat2); // mat1 changes & return
					    // new matrix with the sum
     friend Matrix operator-= (Matrix& mat1, Matrix mat2); // mat1 changes + return new
					     // matrix with difference
     friend Matrix operator+= (Matrix& mat, int scalar);   // change mat & return new matrix
     friend Matrix operator-= (Matrix& mat, int scalar);   // change mat & return new matrix
     friend void   operator++ (Matrix& mat);   	// Add 1 to each element ++mat
     friend void   operator-- (Matrix& mat);

 //--------------------------------------------------------------------Mohamed Ahmed Abdallah  student 1

     friend Matrix operator+  (Matrix mat1, Matrix mat2); // Add if same dimensions
     friend Matrix operator-  (Matrix mat1, Matrix mat2); // Sub if same dimensions
     friend Matrix operator*  (Matrix mat1, Matrix mat2); // Multi if col1 == row2
     friend Matrix operator+  (Matrix mat1, int scalar);  // Add a scalar
     friend Matrix operator-  (Matrix mat1, int scalar);  // Subtract a scalar
     friend Matrix operator*  (Matrix mat1, int scalar);  // Multiple by scalar

};

//------------------------------------------------------------------ Mohamed Khaled Khedr

istream& operator>>(istream& in, Matrix& mat){
    cout << "\n\nPlease enter rows and columns : ";
    cin >> mat.row >> mat.col;
    mat.data.resize(mat.row * mat.col);
    for(int i = 0 ; i < mat.row ; i++){
        cout << "\nPlease enter data for row " << i+1 << " : ";
        for(int j = 0 ; j < mat.col ; j++){
            cin >> mat.data[i * mat.col + j];
        }
    }
    cout<<endl;
}

ostream& operator<<(ostream& out,Matrix mat)
{
    for(int i=0;i<mat.row;i++)
    {
       for(int j=0;j<mat.col;j++){
            out<<mat.data[i*mat.col+j]<<"  ";
     }
     out<<endl<<endl;
}
return out;

}

Matrix operator-= (Matrix& mat1, Matrix mat2) {


    if (mat1.row==mat2.row&&mat1.col==mat2.col)
	{
		mat1.data=mat1.data- mat2.data;
        cout<<"mat1-=mat2 is"<<endl<<endl;
        cout<<mat1;
	    return mat1;
	}
    else
        cout<<"Not allowed as row1 must equal row2 && col1 must equal col2"<<endl;
}


Matrix operator+= (Matrix& mat1, Matrix mat2) {


    if (mat1.row==mat2.row&&mat1.col==mat2.col)
	{
		mat1.data=mat1.data+ mat2.data;
	    cout<<"mat1+=mat2 is"<<endl<<endl;
        cout<<mat1;
        return mat1;
    }

    else
        cout<<"Not allowed as row1 must equal row2 && col1 must equal col2"<<endl;

}

Matrix operator+= (Matrix& mat, int scalar)
{
    mat.data=mat.data+scalar;
    return mat;
}

Matrix operator-= (Matrix& mat, int scalar)
{
    mat.data=mat.data-scalar;
    return mat;
}

void   operator++ (Matrix& mat)
{
    mat.data=mat.data+1;
}

void   operator-- (Matrix& mat)
{
    mat.data=mat.data-1;
}

//------------------------------------------------------------------ Mohamed Ahmed Abdallah

Matrix operator+  (Matrix mat1, Matrix mat2) // Add if same dimensions
{
    Matrix mat3;             //create new matrix to save the result
    mat3.row=mat1.row;      //you should row about mat3==row about mat1
    mat3.col=mat1.col;      //you should col about mat3==mat about mat1
    mat3.data.resize(mat1.row*mat2.col);
    for ( int i=0 ; i<mat1.row*mat1.col ; i++)
    {
        mat3.data[i] = mat1.data[i] + mat2.data[i];  //new matrix=matrix1+matrix2..==add 2 matrix
    }
    return mat3;

}


Matrix operator-  (Matrix mat1, Matrix mat2) // Sub if same dimensions
{

    Matrix mat3;          //create new matrix to save the result
    mat3.row=mat1.row;   //you should row about mat3==row about mat1
    mat3.col=mat1.col;  //you should col about mat3==mat about mat1
    mat3.data.resize(mat1.row*mat2.col);
    for ( int i=0 ; i<mat1.row*mat1.col ; i++)
    {
        mat3.data[i] = mat1.data[i] - mat2.data[i]; //new matrix=matrix1-matrix2..== sub 2 matrix
    }
    return mat3;



}



Matrix operator+  (Matrix mat1, int scalar)  // Add a scalar
{
    Matrix mat3;             //create new matrix to save the result
    mat3.row=mat1.row;      //you should row about mat3==row about mat1
    mat3.col=mat1.col;      //you should col about mat3==mat about mat1
    mat3.data.resize(mat1.row*mat1.col);
    for ( int i=0 ; i<mat1.row*mat1.col ; i++)
    {
        mat3.data[i] = mat1.data[i] + scalar;  //make the calculation and save the result in the new matrix
    }
    return mat3;
}


Matrix operator-  (Matrix mat1, int scalar)   // Subtract a scalar
{
    Matrix mat3;             //create new matrix to save the result
    mat3.row=mat1.row;      //you should row about mat3==row about mat1
    mat3.col=mat1.col;      //you should col 0about mat3==mat about mat1
    mat3.data.resize(mat1.row*mat1.col);
    for ( int i=0 ; i<mat1.row*mat1.col ; i++)
    {
        mat3.data[i] = mat1.data[i] - scalar;  //make the calculation and save the result in the new matrix
    }
    return mat3;

}


Matrix operator*  (Matrix mat1, int scalar)  // Multiple by scalar
{
    Matrix mat3;             //create new matrix to save the result
    mat3.row=mat1.row;      //you should row about mat3==row about mat1
    mat3.col=mat1.col;      //you should col about mat3==mat about mat1
    mat3.data.resize(mat1.row*mat1.col);
    for ( int i=0 ; i<mat1.row*mat1.col ; i++)
    {
        mat3.data[i] = mat1.data[i] * scalar;  //make the calculation and save the result in the new matrix
    }
    return mat3;

}


int main()
{
  Matrix mat1, mat2;
  int x,scalar;

  cout<<"1-for += matrix and for -= matrix"<<endl;
  cout<<"2-for matrix++ and for matrix--"<<endl;
  cout<<"3-for adding scalar to matrix and for subtracting scalar from matrix"<<endl<<endl;

  cout<<"4-Mohamed Ahmed Abdallah functions [(mat1+mat2),(mat1-mat2),(mat+scalar),"<<endl;
  cout<<"                         (mat-scalar),(mat*scalar),(mat1*mat2)]"<<endl<<endl;

  cout<<"press any other numbers or letters to exit"<<endl;

  for (int y=0;y<=30;y++){

  cout<<endl;
  cout<<"***************************\n";
  cout<<"\nplease choose a number : ";
  cin>>x;
  cout<<"\n***************************\n";
  cout<<endl;

  if (x==1){
  cout<<"We do += matrix and -= matrix"<<endl<<endl<<endl;
  cout<<"Now we do += matrix"<<endl<<endl;
  cout<<"enter the first matrix ";
  cin >> mat1 ;
  cout<<endl<<endl<<"enter the second matrix ";
  cin>> mat2 ;
  cout<<"mat1 is "<<endl<<endl;
  cout<<mat1<<endl;
  cout<<"mat2 is "<<endl<<endl;
  cout<<mat2<<endl;
  mat1+=mat2;
  cout<<endl;


  cout<<"Now we do -= matrix"<<endl<<endl;
  cout<<"enter the first matrix ";
  cin >> mat1 ;
  cout<<endl<<endl<<"enter the second matrix ";
  cin>> mat2 ;
  cout<<"mat1 is "<<endl<<endl;
  cout<<mat1<<endl;
  cout<<"mat2 is "<<endl<<endl;
  cout<<mat2<<endl;
  mat1-=mat2;
  }

  else if (x==2){
  cout<<"We do ++matrix and --matrix"<<endl<<endl<<endl;
  cout<<"Now we do ++matrix"<<endl<<endl;
  cout<<"enter your matrix for ++matrix ";
  cin >> mat1;
  cout<<"mat is "<<endl<<endl;
  cout<<mat1<<endl;
  ++mat1;
  cout<<"mat++ is"<<endl<<endl;
  cout<<mat1<<endl<<endl;


  cout<<"Now we do --matrix"<<endl<<endl;
  cout<<"enter your matrix for --matrix ";
  cin >> mat2;
  cout<<"mat is "<<endl<<endl;
  cout<<mat2<<endl;
  --mat2;
  cout<<"mat-- is"<<endl<<endl;
  cout<<mat2;
  }

  else if (x==3){
  cout<<"We add scalar to matrix and subtract it from matrix"<<endl<<endl<<endl;
  cout<<"Now we add scalar to matrix"<<endl<<endl;
  cout<<"enter your matrix ";
  cin >> mat1;
  cout<<"mat is "<<endl<<endl;
  cout<<mat1;
  cout<<"enter a scalar : ";
  cin>>scalar;
  cout<<endl;
  mat1+=scalar;
  cout<<"mat after adding scalar is"<<endl<<endl;
  cout<<mat1<<endl<<endl;


  cout<<"Now we subtract scalar from matrix"<<endl<<endl;
  cout<<"enter your matrix ";
  cin >> mat2;
  cout<<"mat is "<<endl<<endl;
  cout<<mat2;
  cout<<"enter a scalar : ";
  cin>>scalar;
  cout<<endl;
  mat2-=scalar;
  cout<<"mat after subtracting scalar is"<<endl<<endl;
  cout<<mat2;
  }

   else if (x==4){

  int data1 [] = {1,2,3,4,5,6,7,8, 9};
  int data2 [] = {1,1,1,1,1,1,1,1,1};
  int data3 [] = {10,100,10,100,10,100,10,100};

  Matrix mat1, mat2, mat3;
  mat1.createMatrix (3, 3, data1, mat1);
  mat2.createMatrix (3, 3, data2, mat2);
  mat3.createMatrix (4, 2, data3, mat3);


// The next code will not work until you write the functions

  cout<< "mat1 = "<<endl<<endl<<mat1<<endl<<endl;
  cout<<"***************"<<endl;
  cout<< "mat2 = "<<endl<<endl<<mat2<<endl<<endl;
  cout<<"***************"<<endl;

  mat3 = mat1 + mat2 ;
  cout <<"mat3 = mat1 + mat2    " <<endl << endl <<mat3<<endl ;
  cout<<"***************"<<endl;
  mat3 = mat1 - mat2 ;
  cout <<"mat3 = mat1 - mat2  " <<endl << endl <<mat3<<endl ;
  cout<<"***************"<<endl;
  mat3 = mat1 + 4 ;
  cout << "mat3 = mat1 + 4    "<< endl << endl <<mat3 <<endl ;
  cout<<"***************"<<endl;
  mat3 = mat1 - 5 ;
  cout << "mat3 = mat1 - 5    "<< endl << endl << mat3 <<endl ;
  cout<<"***************"<<endl;
  mat3 = mat1 * 3 ;
  cout << "mat3 = mat1 * 3   "<< endl << endl << mat3 <<endl ;
  cout<<"***************"<<endl;


  }

  else{
  cout<<"Now exit"<<endl;
  break;
  }

 }
}

