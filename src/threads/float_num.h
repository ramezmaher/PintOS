/*      The fixed-point representation is achieved by considering the 14 rightmost bits as    */ 
/*      fraction, while there are 17 bits before the the decimal point,    */
/*      and one bit for the sign.    */
struct floatin_num{
    int val;
};
/*      Given a floating number, round it dow if positive and up if negative.   */
int get_int_truncate(struct floatin_num f);
/*      Given a floating number, round it to the nearest integer value.     */
int get_int_roundOff(struct floatin_num f);
/*      Given an integer value, return its representation in 17.14 fixed-point,     */
/*      such operation is achived by right-shifting the integer by 14 bits      */
struct floatin_num get_float(int i);
/*      Returns float n = float x + int y     */
struct floatin_num add_float_int(struct floatin_num x,int y);
/*      Returns float n =  float x + float y       */
struct floatin_num add_float_float(struct floatin_num x,struct floatin_num y);
/*      Returns float n = float x - int y     */
struct floatin_num sub_float_int(struct floatin_num x,int y);
/*      Returns float n = float x - float y       */
struct floatin_num sub_float_float(struct floatin_num x,struct floatin_num y);
/*      Returns float n = float x * int y     */
struct floatin_num mul_float_int(struct floatin_num x,int y);
/*      Returns float n = float x * float y     */
struct floatin_num mul_float_float(struct floatin_num x,struct floatin_num y);
/*      Returns float n = float x / int y       */
struct floatin_num div_float_int(struct floatin_num x,int y);
/*      Returns float n = float x / float y     */
struct floatin_num div_float_float(struct floatin_num x,struct floatin_num y);
