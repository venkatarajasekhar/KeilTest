#include <stdio.h>
// In case you wanna write data into an address.
void write_reg(unsigned volatile int address, unsigned int data)
{
    unsigned volatile int *ptr = 0x0;
    ptr=(unsigned volatile int *) address;
    *ptr=data;
}

// In case you wanna read data into an address.
unsigned int read_reg(unsigned volatile int address)
{
    unsigned volatile int *ptr = NULL;
    ptr=(unsigned volatile int *) address;
    return(*ptr);
}

// In case you wanna set a bit of data at an address.
void set_bit(unsigned volatile int address, unsigned short int bitnumber)
{
    unsigned volatile int *ptr = NULL;
    int reg_data,shift=1;

    ptr      =  (unsigned volatile int *) address;
    reg_data =  (*ptr);
    reg_data =  (reg_data)|(shift<<bitnumber);
    (*ptr)   =  reg_data;

}

// In case you wanna clear a bit of data at an address.
void clear_bit(unsigned volatile int address, unsigned short int bitnumber)
{
    unsigned volatile int *ptr = NULL;
    unsigned int reg_data,shift=1;

    ptr      =  (unsigned volatile int *) address;
    reg_data =  (*ptr);
    reg_data =  (reg_data) & (~(shift<<bitnumber));
    (*ptr)   =  reg_data;

}

// In case you wanna get a bit of data at an address.
unsigned int get_bit(unsigned volatile int address,unsigned short int bitnumber)
{
    unsigned int reg_data,shift=1;
    unsigned volatile int *ptr = NULL;

    ptr      =  (unsigned volatile int *) address;
    reg_data =  (*ptr);
    reg_data =  ( (reg_data)&(shift << bitnumber) ) >> (bitnumber);

    return(reg_data);

} 

//Write Mask operation :
void write_mask(unsigned volatile int address, unsigned int data, unsigned int mask_pattern)
{
	unsigned int data_mask;
    	data_mask=data & (~(mask_pattern));
	write_reg(address,(data_mask|(read_reg(address))));
}

//Read Mask operation :
unsigned int read_mask(unsigned volatile int address,unsigned int mask_pattern)
{
    	return ((read_reg(address)) & (~(mask_pattern)));
}

// Polling flag checking routine :
unsigned int poll_on_set(unsigned volatile int address,unsigned short int bitnumber)
{
        unsigned volatile int *ptr = NULL;
        unsigned int bit_data;
        unsigned int shift=1;

        ptr  =  (unsigned volatile int *) address;

        do									
        {
              bit_data =  (*ptr);
              bit_data =  ( (bit_data)&(shift << bitnumber) ) >> (bitnumber);

        }while(bit_data==0);

        if(bit_data == 1 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

// Polling flag checking routine including limitation on the polling operation :
unsigned int poll_on_set_limit(unsigned volatile int address,unsigned short int bitnumber, unsigned int count)
{
        unsigned volatile int *ptr = NULL;
        unsigned int bit_data;
        unsigned int shift=1;
        unsigned int set_count=0;
	
        ptr  =  (unsigned volatile int *) address;

        do
        {
              bit_data =  (*ptr);
              bit_data =  ( (bit_data)&(shift << bitnumber) ) >> (bitnumber);
	      set_count++;
        }while((bit_data==0) && (set_count < count));

        if(bit_data == 1 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

// Checking routine for dedicated polling flag : 
unsigned int poll_on_reset( unsigned volatile int address, unsigned short int bitnumber )
{
    	unsigned int bit_data;

	do
	{
		bit_data=get_bit(address,bitnumber);

	}while(bit_data==1);
	if(bit_data==0)
        {
	    return 1;
	}
	else
	{
	    return 0;
	}
}
