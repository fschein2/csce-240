// Copyright 2023 fschein
// Program 1
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<iomanip>

int main() {
  char contOrQuit;  // determines if the loop continuation
  float correctCount = 0.0;  // counts the number of correct expressions
  float totalCount = 0.0;  // counts the total number of expressions
  do {
    int val1, val2, val3;  // stores the values input by the user
    char relationalOp, arithmeticOp;  // stores the operators input by the user
    int val4;  // stores the value of the left side of the expression
    bool run;  // stores if we should run the expression

    // input from the user to write the expression
    cin >> val1;
    cin >> arithmeticOp;
    cin >> val2;
    cin >> relationalOp;
    cin >> val3;

    switch ( relationalOp ) {  // checks the relational operator
      case '<':
      case '>':
        run = true;  // run the expression
        switch ( arithmeticOp ) {  // checks the arthimetic operator
        case '+':
          val4 = val1 + val2;
          break;
        case '-':
          val4 = val1 - val2;
          break;
        case '*':
         val4 = val1 * val2;
         break;
        case '/':
         val4 = val1 / val2;
         break;
        case '%':
         val4 = val1 % val2;
         break;
        default:
         run = false;  // do not run the expression
        }
        break;
      default:
        run = false;  // do not run the expression
    }

    if ( !run ) {
      if ( arithmeticOp != '+' ) {
       if ( arithmeticOp != '-' ) {
         if ( arithmeticOp != '*' ) {
           if ( arithmeticOp != '/' ) {
            if ( arithmeticOp != '%' ) {
              cout << "Unrecognized arithmetic operator ";
              cout << arithmeticOp << endl;
            }
           }
          }
        }
      }
      if ( relationalOp != '>' ) {
       if ( relationalOp != '<' ) {
         cout << "Unrecognized relational operator " << relationalOp << endl;
        }
      }
    }

    if ( run ) {
      if ( relationalOp == '<' ) {
        cout << val1 << " " << arithmeticOp << " " << val2 << " ";
        cout << relationalOp << " " << val3;
        if ( val4 < val3 ) {
          ++correctCount;
          ++totalCount;
          cout << " - Correct" << endl;
        } else {
            ++totalCount;
            cout << " - Incorrect" << endl;
        }
      } else if ( relationalOp == '>' ) {
          cout << val1 << " " << arithmeticOp << " " << val2 << " ";
          cout << relationalOp << " " << val3;
          if ( val4 > val3 ) {
            ++correctCount;
            ++totalCount;
            cout << " - Correct" << endl;
          } else {
            ++totalCount;
            cout << " - Incorrect" << endl;
          }
      }
    }

    cin >> contOrQuit;  
  } while ( contOrQuit == 'c' );

  float correctness;  // stores the percentage of correct expressions
  correctness = correctCount / totalCount;
  correctness = correctness * 100;
  cout << correctCount << " of " << totalCount << " = ";
  cout << std::setprecision(2);
  cout << std::setiosflags(std::ios::showpoint | std::ios::fixed);
  if ( totalCount == 0 ) {
    cout << "0.00%" << endl;
  } else {
      cout << correctness << "%" << endl;
  }
}
