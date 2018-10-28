// Euclid
// Implementation of Euclid's Algorithm for deriving the largest common divisor
// betwixt two numbers.
//
// Copyright (C) 2018 Gregory Hedger
#include <string.h>
#include <iostream>

using namespace std;

bool valid( int m, int n )
{
  if( ( n && m ) && ( m > n  ) )
    return true;
  return false;
}

void printUsage()
{
  cout << "Euclid's algorithm" << endl;
  cout << "Usage:" << endl << endl;
  cout << "\teuclid <number_a> <number_b> [-v]" << endl;
  cout << endl;
  cout << "where" << endl;
  cout << "\tnumber_a > number_b" << endl;
  cout << endl;
  cout << "-v - Verbose output, showing steps." << endl;
}

void printNoSolution()
{
  cout << "No solution found." << endl;
}

void printSolution( int answer, int iterations )
{
  cout << answer << endl;
  cout << "(" << iterations << " iterations)"<< endl;
}

int main( int argc, char *argv[] )
{
  if( argc < 3 ) {
    printUsage();
    return -1;
  }

  int m, n, r;
  bool verbose;
  unsigned it = 1;
  sscanf( argv[1], "%d", &m );
  sscanf( argv[2], "%d", &n );
  if( 3 < argc ) {
    if( !strcmp( argv[3], "-v" ) )
      verbose = true;
  }

  if( valid( m, n ) ) {
    do {
    // Begin the algorithm
    // Find remainder

    r = m % n;
    if( verbose )
      cout << m << " % " << n << " = " << r << endl;

    // Check for terminal condition of 0 == r
    if( !r ) {
      printSolution( n, it );
      break;
    }

    // Reduction
    if( verbose )
      cout << "\033[1;33m" << m << " <- " << n << ", " << n << " <- " << r << "\033[1;37m" << endl;

    m = n;
    n = r;

    } while( ++it );
    if( !it ) {
      printNoSolution();
    }

  } else {
    printUsage();
    return -1;
  }
  return 0;
}
