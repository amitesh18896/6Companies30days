long long int number_of_square(int n)
{
  return n*(n+1)*(2*n+1)/6;  // summation of n square
}

// example 8*8 chessboard
// squares = 8*8 = 64 (1x1) +.....
//+ 1*1=1 (8x8 square)
