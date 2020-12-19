/*      The 17.14 fixed-point representation of real numbers is based on shifting the binary point  */
/*      of the number to the right by 14 bits, which is similar to representing 1.2 as 12 by multiplying */
/*      the digit 2 by 10 we shift the decimal point to the right.  */
/*      This is achieved in computers for binary numbers by applying left shift     */
/*      by multiplying each real number by 2^14 we give room for representing 14 more digits    */
/*      of the fraction, with limitations on the precision and the maximum size of integer that can be represented. */
/*      In computers there are 2 ways to represent real numbers, 1-fixed point 2-floating points.   */
/*      While floating point does better in percision and gives a wider range of numbers that could be represented, */
/*      it is actually costly in terms of time, this is why it is usually done in the hardware by a floating point component.   */
/*      For our implementation we use fixed point representation because we value efficiency and speed over accuracy    */
/*      in the implementation of a real-time system such as an operating system.*/
struct real{
    int val;
};
/*      Given a real number, round it down if positive and up if negative.   */
int get_int_truncate(struct real f);
/*      Given a real number, round it to the nearest integer value.     */
int get_int_roundOff(struct real f);
/*      Given an integer value, return its representation in 17.14 fixed-point,     */
/*      such operation is achived by left-shifting the integer by 14 bits      */
struct real get_real(int i);
/*      Returns real n = real x + int y     */
struct real add_real_int(struct real x,int y);
/*      Returns real n =  real x + real y       */
struct real add_real_real(struct real x,struct real y);
/*      Returns real n = real x - int y     */
struct real sub_real_int(struct real x,int y);
/*      Returns real n = real x - real y       */
struct real sub_real_real(struct real x,struct real y);
/*      Returns real n = real x * int y     */
struct real mul_real_int(struct real x,int y);
/*      Returns real n = real x * real y     */
struct real mul_real_real(struct real x,struct real y);
/*      Returns real n = real x / int y       */
struct real div_real_int(struct real x,int y);
/*      Returns real n = real x / real y     */
struct real div_real_real(struct real x,struct real y);
