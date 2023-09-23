/* ARM Corex M3 Startup code
By: Eng. Amr Zidan */

/* SRAM from 0x20000000 */
.section .vectors
.word 0x20001000        /*stack top address*/
.word _reset            /*1 reset*/
.word _vector_handler   /*2 NMI*/
.word _vector_handler   /*3 Hard Fault*/
.word _vector_handler   /*4 MM Fault*/
.word _vector_handler   /*5 Bus Fault*/
.word _vector_handler   /*6 Usage Fault*/
.word _vector_handler   /*7 Reserved*/
.word _vector_handler   /*8 Reserved*/
.word _vector_handler   /*9 Reserved*/
.word _vector_handler   /*10 Reserved*/
.word _vector_handler   /*11 SV Call*/
.word _vector_handler   /*12 Debug Rserved*/
.word _vector_handler   /*13 Reserved*/
.word _vector_handler   /*14 Pend SV*/
.word _vector_handler   /*15 SysTick*/
.word _vector_handler   /*16 TRQ0*/  
.word _vector_handler   /*17 TRQ1*/ 
.word _vector_handler   /*18 TRQ2*/ 
.word _vector_handler   /*19 ...*/

.section .text
_reset: 
    bl main
    b .

.thumb_func

_vector_handler:
    b _reset