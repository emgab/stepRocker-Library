volatile int  *STRADDR = (volatile int *)0x20008000 ;
volatile char *CHRADDR = (volatile char *)(0x20008000 + 0x4) ;
volatile int  *HEXADDR = (volatile int *)(0x20008000 + 0x8) ;

void CSP_WriteStr(char *str) {

     int cntnum = 0 ;
     int accnum = 0 ;
     int resnum = 0 ;
     int tnum = 0 ;

     while(*(str + cntnum) != '\0') { cntnum++ ; } /* Get the Total Number of Byte */
     accnum = cntnum/4 ;
     resnum = cntnum%4 ;

     while(accnum > tnum) {
           *STRADDR = *((int *)(str) + tnum) ;
           tnum++ ;
     }
     tnum = 0 ;
     while(resnum > tnum) {
           *CHRADDR = *(char *)(str + 4*accnum + tnum) ;
           tnum++ ;
     }
} /* End of Write String */

void CSP_WriteHex(int value) {
     *HEXADDR = value ;
} /* End of Write Hexadecimal Value */

void CSP_WriteDec(int value) {
     int residue ;
     int char_ar[13] ;
     int i = 0 ;
     if(value == 0) {
        *CHRADDR = '0' ;
     }
     else if(value >0) {
       while (value != 0) {
              residue = value % 10 ; //Get the Residue
	      value = value/10 ; //Get the New Value
	      char_ar[i] = (char)residue + 0x30 ;
	      i++ ;
       }
       while (i > 0) {
	      *CHRADDR = char_ar[i-1] ;
	      i-- ;
       }
     }
     else {
       *CHRADDR = '-' ;
       value = (~value + 1) ;
       while (value != 0) {
              residue = value % 10 ; //Get the Residue
	      value = value/10 ; //Get the New Value
	      char_ar[i] = (char)residue + 0x30 ;
	      i++ ;
       }
       while (i > 0) {
	      *CHRADDR = char_ar[i-1] ;
	      i-- ;
       }
     }
}

void CSP_WriteChar(char *str) {
     *CHRADDR = *(char *)str ;
} /* End of Write Character */

void CSP_ChkRegValue(unsigned addr, unsigned matchval, unsigned mask, char *str) {
     unsigned rdval ;
     rdval = *(unsigned int *)(addr) & mask ;
     // Kookpyo Lee 2003.12.18
     //if(rdval == matchval) {
     if(rdval == (matchval & mask)) {
        CSP_WriteStr(str) ;
        CSP_WriteChar(" ") ;
        CSP_WriteStr("Match OK \n") ;
     }
     else {
        CSP_WriteStr(str) ;
        CSP_WriteHex((int)rdval) ;
        CSP_WriteHex((int)rdval) ;
        CSP_WriteStr(" != ") ;
        CSP_WriteHex(matchval & mask) ;
        CSP_WriteChar("\n") ;
     }
}
 
int CSP_CompareValue(int source, int destination)
{
	int resultflag = 0;

	if (source == destination)
  	{
    	resultflag = 1;
  	}  
  	return (resultflag);
}
						