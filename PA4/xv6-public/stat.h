#define T_DIR  1   // Directory
#define T_FILE 2   // File
#define T_DEV  3   // Device

/////////////////////////////////////////
#define T_EXTENTFILE 4 // extent-based file


struct extentsinfo
{

  uint address:24,// 24 bits for extent pointers
       length:8; //  8 bits for extent length
  
};




//////////////////////////////////////
struct stat {
  short type;  // Type of file
  int dev;     // File system's disk device
  uint ino;    // Inode number
  short nlink; // Number of links to file
  uint size;   // Size of file in bytes


  /////////////////////////////
  struct extentsinfo extents[12];  //extent-based file
  ////////////////////////////
};

