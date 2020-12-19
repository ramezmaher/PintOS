#include <stdint.h>
#include <stdint.h>
#include "float_num.h"

/*      Given a floating number, round it dow if positive and up if negative.   */
int get_int_truncate(struct floatin_num f){
    return (f.val >> 14);
}
/*      Given a floating number, round it to the nearest integer value.     */
int get_int_roundOff(struct floatin_num f){
    int x = 1 << 13;
    if(f.val < 0){
        return ((f.val - x) >> 14);
    }
    else{
        return ((f.val + x) >> 14);
    }
}
/*      Given an integer value, return its representation in 17.14 fixed-point,     */
/*      such operation is achived by right-shifting the integer by 14 bits      */
struct floatin_num get_float(int i){
    struct floatin_num f;
    f.val = i << 14;
    return f;
}
/*      Returns float n = float x + int y     */
struct floatin_num add_float_int(struct floatin_num x,int y){
    struct floatin_num n;
    n.val = x.val + ( y << 14 );
    return n;
}
/*      Returns float n =  float x + float y       */
struct floatin_num add_float_float(struct floatin_num x,struct floatin_num y){
    struct floatin_num n;
    n.val = x.val + y.val;
    return n;
}
/*      Returns float n = float x - int y     */
struct floatin_num sub_float_int(struct floatin_num x,int y){
    struct floatin_num n;
    n.val = x.val - (y << 14);
    return n;
}
/*      Returns float n = float x - float y       */
struct floatin_num sub_float_float(struct floatin_num x,struct floatin_num y){
    struct floatin_num n;
    n.val = x.val - y.val;
    return n;
}
/*      Returns float n = float x * int y     */
struct floatin_num mul_float_int(struct floatin_num x,int y){
    struct floatin_num n;
    n.val = x.val * y;
    return n; 
}
/*      Returns float n = float x * float y     */
struct floatin_num mul_float_float(struct floatin_num x,struct floatin_num y){
    struct floatin_num n;
    n.val = (((__int64_t) x.val) * y.val ) >> 14;
    return n;
} 
/*      Returns float n = float x / int y       */
struct floatin_num div_float_int(struct floatin_num x,int y){
    struct floatin_num n;
    n.val = x.val / y;
    return n;
}
/*      Returns float n = float x / float y     */
struct floatin_num div_float_float(struct floatin_num x,struct floatin_num y){
    struct floatin_num n;
    n.val = (((int64_t)x.val) << 14 ) / y.val;
    return n;
}

