
void write_reg(unsigned volatile int address, unsigned int data);
unsigned int read_reg(unsigned volatile int address);
void set_bit(unsigned volatile int address, unsigned short int bitnumber);
void clear_bit(unsigned volatile int address, unsigned short int bitnumber);
unsigned int get_bit(unsigned volatile int address,unsigned short int bitnumber);
void write_mask(unsigned volatile int address, unsigned int data, unsigned int mask_pattern);
unsigned int read_mask(unsigned volatile int address,unsigned int mask_pattern);
unsigned int poll_on_set(unsigned volatile int address,unsigned short int bitnumber);
unsigned int poll_on_set_limit(unsigned volatile int address,unsigned short int bitnumber, unsigned int count);
unsigned int poll_on_reset( unsigned volatile int address, unsigned short int bitnumber );
