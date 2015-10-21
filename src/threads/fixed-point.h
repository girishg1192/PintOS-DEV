#define EXPONENT 16384

  int32_t int_to_fp(int32_t n);
  int32_t add_to_fp(int32_t x, int32_t n);
  int32_t sub_from_fp(int32_t x, int32_t n);
  int32_t mul_fp_int(int32_t x, int32_t n);
  int32_t mul_fp_fp(int32_t x, int32_t y);
  int32_t div_fp_fp(int32_t x, int32_t y);
  int32_t div_fp_int(int32_t x, int32_t n);

int32_t int_to_fp(int32_t n)
{
  return n*EXPONENT;
}
int32_t fp_to_int(int32_t x)
{
  if(x < 0)
    return (x - EXPONENT/2)/EXPONENT;
  else
    return (x + EXPONENT/2)/EXPONENT;
}
int32_t add_to_fp(int32_t x, int32_t n)
{
  return x+n*EXPONENT;
}
int32_t sub_from_fp(int32_t x, int32_t n)
{
  return x-n*EXPONENT;
}
int32_t mul_fp_int(int32_t x, int32_t n)
{
  return x*n;
}
int32_t mul_fp_fp(int32_t x, int32_t y)
{
   return (((int64_t) x)*y)/EXPONENT;
}
int32_t div_fp_fp(int32_t x, int32_t y)
{
  return (((int64_t) x)*EXPONENT)/y;
}
int32_t div_fp_int(int32_t x, int32_t n)
{
  return x/n;
}
