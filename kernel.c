/*
* Created by jeremy.king on 11/24/2020.
* kernel project version 0.01a
*/

void kmain(void)//this is the function called in the assembly file kernel.asm
{
    const char *str = "my first kernel";
    char *vidptr = (char*)0xb8000; //this address is the start of video memory
    unsigned int i = 0;
    unsigned int j = 0;

    /*this loop clears the screen
     * there are 25 lines each 80 columns; each element takes 2 bytes */
    while(j<80*25*2){
        //blank char
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07;
        j = j + 2;
    }
    j = 0;

    //this loop writes the string to video memory
    while(str[j] != '\0'){
        //the characters ascii
        vidptr[i] = str[j];
        //attribute-byte give character black bg and light fg
        vidptr[i+1] = 0x07;
        ++j;
        i = i+2;
    }
    return;
}
