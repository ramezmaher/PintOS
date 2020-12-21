#include <stdint.h>
#include <stdint.h>
#include "real_num.h"

/*      Given a real number, round it dow if positive and up if negative.   */
/*      Right shift is similar to devision, hence we truncate the least-significant 14 bits.    */
int get_int_truncate(struct real f){
    return (f.val >> 14);
}
/*      Given a real number, round it to the nearest integer value.     */
/*      By adding 1 to the second most significant digit of the least significant 14 bits -the 13th-,  */
/*      if the next digit -the 14th- was affected, then the number is closer to the next integer,   */  
/*      hence the real number is rounded to it.     */
int get_int_roundOff(struct real f){
    int x = 1 << 13;
    if(f.val < 0){
        return ((f.val - x) >> 14);
    }
    else{
        return ((f.val + x) >> 14);
    }
}
/*      Given an integer value, return its representation in 17.14 fixed-point,     */
/*      such operation is achived by left-shifting the integer by 14 bits.      */
struct real get_real(int i){
    struct real f;
    f.val = i << 14;
    return f;
}
/*      Given two integers x,y return x/y in fixed point format     */
struct real get_real_fraction(int x, int y){
    struct real f1,f2;
    f1 = get_real(x);
    f2 = get_real(y);
    return div_real_real(f1,f2);
}
/*      Returns real n = real x + int y     */
struct real add_real_int(struct real x,int y){
    struct real n;
    n.val = x.val + ( y << 14 );
    return n;
}
/*      Returns real n =  real x + real y       */
struct real add_real_real(struct real x,struct real y){
    struct real n;
    n.val = x.val + y.val;
    return n;
}
/*      Returns real n = real x - int y     */
struct real sub_real_int(struct real x,int y){
    struct real n;
    n.val = x.val - (y << 14);
    return n;
}
/*      Returns real n = real x - real y       */
struct real sub_real_real(struct real x,struct real y){
    struct real n;
    n.val = x.val - y.val;
    return n;
}
/*      Returns real n = real x * int y     */
struct real mul_real_int(struct real x,int y){
    struct real n;
    n.val = x.val * y;
    return n; 
}
/*      Returns real n = real x * real y     */
/*      The first real number is cast to 64-bit integer to avoid overflow of the multiplication.    */
struct real mul_real_real(struct real x,struct real y){
    struct real n;
    n.val = (((int64_t) x.val) * y.val ) >> 14;
    return n;
} 
/*      Returns real n = real x / int y       */
struct real div_real_int(struct real x,int y){
    struct real n;
    n.val = x.val / y;
    return n;
}
/*      Returns real n = real x / real y     */
/*      The first real number is cast to 64-bit integer to avoid overflow of the division.  */
struct real div_real_real(struct real x,struct real y){
    struct real n;
    n.val = (((int64_t)x.val) << 14 ) / y.val;
    return n;
}

