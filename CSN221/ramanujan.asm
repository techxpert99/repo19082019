/* 
#####################################
### AUTHOR : RITIK JAIN           ###
### ENROLMENT NUMBER : 18114068   ###
### BTECH. CSE : O3               ###
#####################################
*/

/*
############################################################################
### Let r10 store the memory location where the result is to be stored.  ###
############################################################################
/*

/*
#############################
### Start of main function  #
#############################
*/
.main :

/* Finds smallest Ramanujan */
.smallest_ramanujan :

/* N = 1 initially */
mov r6,1

/* Loop to find the smallest ramanujan */
.loop0 :

/* Calling to check whether or not N is ramanujan. Result is stored in r0 */
call .ramanujan

/* If N is ramanujan goto end */
cmp r0,1
beq end

/* If not : N++ ; repeat the loop */
add r6,r6,1
b loop0

/*
#############################
### End of main function  ###
#############################
*/


/*
###################################################
### Ramanujan check function 			###
### Checks whether a number is ramanujan or not ###
###################################################
*/
.ramanujan :

/* save number from r6 in r0 */
mov r0,r6

/* Declare three variables : i,j,k */
mov r1,1
mov r2,1
mov r3,0

/* The outer loop Loop 1 */
.loop1 :

/* Compare i and N . If i > N break the loop and jump to loopend */
cmp r1,r0
bgt loop1end

/* Initialize : j=1 */
mov r2,1

/* If a pair of cubes with sum = N is detected  , the solution counter (c) is incremented by 1 */
.loop2eq :
add r5,r5,1

/* The inner loop Loop 2 */
.loop2 :

/* Compare i and N . If i > N break the loop and jump to loop2end */
cmp r2,r0
bgt loop2end

/* Declare : tmp1 = i*i*i */
mul r3,r1,r1
mul r3,r3,r1

/* Declare : tmp2 = j*j*j */
mul r4,r2,r2
mul r4,r4,r2

/* Assign : tmp1 = tmp1 + tmp2 = i*i*i + j*j*j */
add r3,r3,r4

/* Compare N and tmp1 = i^3 + j^3 */
cmp r0,r3

/* Increment j [ inner-loop iterator ] : j++ */
add r2,r2,1

/* If N = tmp1 goto loop2eq [ to increment solution counter (c) ] and restart the inner loop*/
beq loop2eq

/* Else restart the inner loop without incrementing c */
b loop2

/* End label of inner loop ; increments i : i++ ; and restarts the outer loop */
.loop2end :
add r1,r1,1
b loop1

/* End label of outer loop ; Compares c and 1 ; If c > 1 Then the number is Ramanujan */
.loop1end :
cmp r5,1

/* If Ramanujan ; Stores 1 in r0 by jumping to store1 label */
bgt .store1

/* Stores 0 in r0 if not ramanujan and returns */
mov r0,0
ret

/*Stores 1 in r0 if ramanujan and returns */
.store1 :
mov r0,1
ret

/*
#######################################
### End of Ramanujan Check function ###
#######################################
*/


/*
   The end label is only reached when the smallest Ramanujan has been stored in r0 ;
   The result is then stored in the memory location mentioned in r10 and halts
*/
.end :
st r0,0[r10]
halt

/*
#######################
### End of the code ###
#######################
*/
