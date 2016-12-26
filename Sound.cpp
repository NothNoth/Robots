#include "Arduboy.h"
#include "Sound.h"
const unsigned char PROGMEM score [] = {
0x90,24, 0x91,36, 0,156, 0,143, 0x90,24, 0x91,36, 0,6, 0,68, 0,81, 0,131, 0x80, 0,12, 0x90,48, 0,6, 
0,6, 0x81, 0,62, 0,6, 0,68, 0x90,53, 0x91,53, 0,6, 0,106, 0,37, 0x91,24, 0x90,48, 0,6, 0,75, 
0,68, 0x90,53, 0,6, 0,56, 0,50, 0,37, 0x90,24, 0,6, 0,25, 0x81, 0,31, 0,18, 0,68, 0x91,55, 
0,6, 0,56, 0,87, 0x91,24, 0x90,24, 0,6, 0,56, 0,87, 0,6, 0,143, 0,6, 0x91,55, 0x90,55, 
0,43, 0,12, 0,87, 0,6, 0,106, 0x80, 0x81, 0,37, 0x90,24, 0x91,24, 0,6, 0,43, 0,6, 0,93, 
0,6, 0,31, 0,75, 0,25, 0x80, 0x81, 0,12, 0x90,24, 0x91,60, 0,6, 0,18, 0,31, 0,31, 0,62, 
0x91,65, 0,6, 0,31, 0,112, 0x90,24, 0x91,60, 0,6, 0,81, 0,18, 0,43, 0x91,65, 0,6, 0,137, 
0x80, 0,6, 0x90,24, 0x91,65, 0,6, 0,68, 0,31, 0,43, 0x91,67, 0,6, 0,68, 0,75, 0x91,24, 0x90,24, 
0,6, 0,68, 0,18, 0,56, 0,6, 0,68, 0,75, 0,6, 0,12, 0,6, 0x80, 0x81, 0,68, 0,18, 
0,37, 0x90,72, 0x91,77, 0,6, 0,68, 0,75, 0x90,24, 0x91,67, 0,6, 0,81, 0,25, 0,37, 0x91,72, 
0,6, 0,131, 0,6, 0x80, 0,6, 0x90,24, 0x91,72, 0,6, 0,50, 0,31, 0,62, 0x91,77, 0,6, 0,93, 
0,50, 0x91,24, 0x90,24, 0,6, 0,50, 0,25, 0,68, 0,6, 0,56, 0,37, 0,31, 0,12, 0x80, 0x81, 
0,6, 0x90,24, 0x91,79, 0,6, 0,68, 0,6, 0,68, 0x91,80, 0,6, 0,56, 0,87, 0x91,42, 0x90,42, 
0,6, 0,56, 0,12, 0x80, 0x81, 0,75, 0x90,77, 0x91,77, 0,6, 0,81, 0,50, 0,6, 0,6, 0x90,42, 
0x91,73, 0,6, 0,56, 0,25, 0x80, 0,62, 0x91,80, 0x90,77, 0,6, 0,81, 0,12, 0,50, 0x90,24, 0x91,73, 
0,6, 0,56, 0,25, 0,18, 0,43, 0x91,77, 0,6, 0,75, 0,18, 0,43, 0x80, 0,6, 0x90,42, 0x91,73, 
0,6, 0,81, 0,18, 0x80, 0,12, 0,31, 0x91,69, 0x90,77, 0,6, 0,75, 0,68, 0x90,24, 0x91,68, 0,6, 
0,81, 0,6, 0,25, 0,31, 0x91,65, 0,6, 0,131, 0,6, 0x80, 0,6, 0x90,42, 0x91,24, 0,6, 0,62, 
0,25, 0,18, 0x80, 0,37, 0x90,68, 0,6, 0,125, 0,18, 0x91,42, 0x90,24, 0,6, 0,62, 0,18, 0,18, 
0x81, 0,43, 0x91,61, 0,6, 0,68, 0,56, 0,18, 0x91,57, 0x90,36, 0,6, 0,62, 0,18, 0,31, 0,31, 
0x91,66, 0,6, 0,68, 0,6, 0,68, 0x90,42, 0x91,24, 0,6, 0,62, 0,6, 0,25, 0x80, 0,50, 0x90,61, 
0,6, 0,75, 0,68, 0x90,57, 0,6, 0,6, 0x81, 0,62, 0,6, 0,37, 0,31, 0x90,56, 0x91,61, 0,6, 
0,87, 0,56, 0x90,24, 0x91,54, 0,6, 0,75, 0,25, 0,43, 0x91,49, 0,6, 0,68, 0,18, 0,56, 
0x91,54, 0,6, 0x90,60, 0,75, 0,25, 0,18, 0,25, 0x91,56, 0,6, 0,68, 0x80, 0,75, 0x90,42, 0x91,24, 
0,6, 0,75, 0,25, 0x80, 0,43, 0x90,56, 0,6, 0,137, 0x81, 0,6, 0x90,42, 0x91,24, 0,6, 0,37, 
0,37, 0,37, 0x80, 0,31, 0x90,69, 0,6, 0,106, 0,37, 0x91,42, 0x90,24, 0,6, 0,75, 0,6, 0,31, 
0x81, 0,31, 0x91,61, 0,6, 0,62, 0,43, 0,37, 0x91,48, 0x90,36, 0,6, 0,62, 0,18, 0,31, 0,31, 
0x91,53, 0,6, 0,62, 0,18, 0,62, 0x90,42, 0x91,24, 0,6, 0,62, 0,6, 0,25, 0x80, 0,50, 0x90,60, 
0,6, 0,81, 0,50, 0x81, 0,12, 0x91,42, 0x90,53, 0,6, 0,6, 0,56, 0,6, 0,50, 0x81, 0,25, 
0x90,55, 0x91,60, 0,6, 0,100, 0,43, 0x90,24, 0x91,53, 0,6, 0,62, 0,12, 0,31, 0,37, 0x91,65, 
0,6, 0,68, 0,31, 0,43, 0x91,60, 0,6, 0,25, 0x80, 0,50, 0,43, 0,18, 0,6, 0x91,60, 0x90,65, 
0,6, 0,68, 0,75, 0x90,24, 0x91,65, 0,6, 0,81, 0,6, 0,31, 0,25, 0x91,60, 0,6, 0,143, 
0x91,42, 0,6, 0x90,55, 0,68, 0,12, 0,25, 0x81, 0,37, 0x91,65, 0,6, 0,118, 0x80, 0,25, 0x90,42, 
0x91,24, 0,6, 0,68, 0,37, 0x80, 0,37, 0x90,72, 0,6, 0,68, 0,50, 0,12, 0x81, 0,12, 0x91,42, 
0x90,67, 0,6, 0,18, 0,43, 0,6, 0,31, 0x81, 0,43, 0x90,79, 0x91,72, 0,6, 0,68, 0,6, 0,68, 
0x90,24, 0x91,67, 0,6, 0,62, 0,6, 0,75, 0x91,72, 0,6, 0,75, 0,62, 0x80, 0,6, 0x90,24, 0x91,67, 
0,6, 0,68, 0,75, 0x91,72, 0,6, 0,106, 0,37, 0x91,24, 0x90,24, 0,6, 0,68, 0,18, 0,56, 
0,6, 0,100, 0,6, 0,37, 0,6, 0,12, 0,6, 0x80, 0x81, 0,68, 0,12, 0,43, 0x90,77, 0x91,67, 
0,6, 0,100, 0,43, 0x90,24, 0x91,72, 0,6, 0,93, 0,6, 0,43, 0x91,77, 0,6, 0,131, 0,6, 
0x80, 0,6, 0x90,24, 0x91,77, 0,6, 0,68, 0,25, 0,50, 0x91,79, 0,6, 0,93, 0,50, 0x91,24, 0x90,24, 
0,6, 0,68, 0,75, 0,6, 0,87, 0,6, 0,31, 0,12, 0x80, 0x81, 0,6, 0x90,24, 0x91,84, 0,6, 
0,68, 0,18, 0,56, 0x91,85, 0,6, 0,81, 0,6, 0,56, 0x90,42, 0x91,24, 0,6, 0,62, 0,6, 
0x80, 0,18, 0,56, 0x90,79, 0,6, 0,81, 0,50, 0,6, 0x81, 0,6, 0x90,42, 0x91,24, 0,6, 0,62, 
0,6, 0,25, 0x80, 0,50, 0x90,80, 0,6, 0,75, 0,68, 0x91,42, 0x90,24, 0,6, 0,68, 0,6, 0x81, 
0,6, 0,62, 0x91,77, 0,6, 0,75, 0,62, 0x80, 0,6, 0x90,42, 0x91,79, 0,6, 0,81, 0x80, 0,25, 
0,37, 0x91,77, 0x90,79, 0,6, 0,75, 0,68, 0x91,42, 0x90,24, 0,6, 0,75, 0,12, 0x81, 0,18, 0,37, 
0x91,73, 0,6, 0,131, 0,6, 0x80, 0,6, 0x90,42, 0x91,24, 0,6, 0,75, 0,31, 0x80, 0,37, 0x90,77, 
0,6, 0,93, 0,50, 0x91,42, 0x90,24, 0,6, 0,75, 0,37, 0x81, 0,31, 0x91,69, 0,6, 0,75, 0,18, 
0,50, 0x91,73, 0x90,36, 0,6, 0,75, 0,6, 0,18, 0,43, 0x91,69, 0,6, 0,68, 0,6, 0,68, 
0x90,42, 0x91,24, 0,6, 0,56, 0,25, 0,12, 0x80, 0,50, 0x90,65, 0,6, 0,68, 0,75, 0x90,68, 0,6, 
0,6, 0x81, 0,50, 0,25, 0,25, 0,37, 0x90,68, 0x91,65, 0,6, 0,87, 0,56, 0x90,24, 0x91,65, 0,6, 
0,81, 0,12, 0,50, 0x91,61, 0,6, 0,75, 0,12, 0,56, 0x91,57, 0,6, 0x90,60, 0,81, 0,25, 
0,6, 0,31, 0x91,61, 0,6, 0,75, 0x80, 0,68, 0x90,42, 0x91,24, 0,68, 0,25, 0x80, 0,18, 0,37, 
0x90,61, 0,6, 0,137, 0x81, 0,6, 0x90,42, 0x91,24, 0,6, 0,37, 0,25, 0,6, 0,50, 0x80, 0,25, 
0x90,56, 0,6, 0,106, 0,37, 0x91,42, 0x90,24, 0,6, 0,68, 0,18, 0,12, 0x81, 0,43, 0x91,49, 0,6, 
0,68, 0,37, 0,37, 0x91,54, 0x90,32, 0,6, 0,87, 0,56, 0x91,49, 0,6, 0,68, 0,75, 0x91,20, 
0x90,20, 0,6, 0,68, 0,18, 0,62, 0,131, 0x80, 0x81, 0,12, 0x90,20, 0x91,32, 0,6, 0,6, 0,62, 
0,6, 0,75, 0,106, 0,37, 0x90,20, 0x91,32, 0,6, 0,75, 0,75, 0,56, 0,50, 0,37, 0,6, 
0,25, 0x80, 0x81, 0,31, 0,18, 0,75, 0x90,44, 0x91,44, 0,56, 0,87, 0,6, 0,56, 0x80, 0x81, 0,93, 
0x90,44, 0x91,44, 0,143, 0,6, 0,43, 0,12, 0x80, 0x81, 0,93, 0x90,58, 0x91,58, 0,106, 0,37, 0,6, 
0,43, 0,6, 0x80, 0x81, 0,100, 0x90,51, 0x91,58, 0,31, 0,75, 0,25, 0,12, 0,6, 0,18, 0,31, 
0x81, 0,31, 0x80, 0,68, 0x90,51, 0x91,44, 0,31, 0,112, 0,6, 0,81, 0x80, 0,18, 0x81, 0,50, 0x90,59, 
0x91,44, 0,137, 0,6, 0,6, 0,68, 0x80, 0,31, 0x81, 0,50, 0x90,58, 0x91,58, 0,68, 0,75, 0,6, 
0,68, 0,18, 0x80, 0x81, 0,62, 0x90,44, 0x91,58, 0,68, 0,75, 0,6, 0,12, 0,6, 0,68, 0x81, 0,18, 
0x80, 0,43, 0x90,44, 0x91,44, 0,68, 0,75, 0,6, 0,81, 0x81, 0,25, 0x80, 0,43, 0x90,44, 0x91,44, 0,131, 
0,6, 0,6, 0,6, 0,50, 0,31, 0x80, 0x81, 0,68, 0x90,58, 0x91,58, 0,93, 0,50, 0,6, 0,50, 
0,25, 0x80, 0x81, 0,75, 0x90,51, 0x91,58, 0,56, 0,37, 0,31, 0,12, 0,6, 0,6, 0,68, 0x80, 0,6, 
0x81, 0,75, 0x90,51, 0x91,44, 0,56, 0,87, 0,6, 0,56, 0x81, 0,12, 0x80, 0,81, 0x90,59, 0x91,44, 0,131, 
0,6, 0,6, 0,6, 0,56, 0x80, 0x81, 0,25, 0,68, 0x90,58, 0x91,58, 0,93, 0,50, 0,6, 0,56, 
0,25, 0x80, 0x81, 0,18, 0,50, 0x90,58, 0x91,52, 0,75, 0,18, 0,43, 0,6, 0,6, 0,81, 0x80, 0,18, 
0,12, 0x81, 0,37, 0x90,52, 0x91,44, 0,75, 0,68, 0,6, 0,81, 0,6, 0x81, 0,25, 0x80, 0,37, 0x90,44, 
0x91,59, 0,131, 0,6, 0,6, 0,6, 0,62, 0x81, 0,25, 0x80, 0,18, 0,43, 0x90,58, 0x91,58, 0,125, 
0,18, 0,6, 0,62, 0,18, 0x80, 0x81, 0,18, 0,50, 0x90,58, 0x91,52, 0,68, 0,56, 0,18, 0,6, 
0,62, 0x81, 0,18, 0x80, 0,31, 0,37, 0x90,52, 0x91,52, 0,68, 0,6, 0,68, 0,6, 0,62, 0x80, 0x81, 
0,6, 0,25, 0,56, 0x90,56, 0x91,56, 0,75, 0,68, 0,6, 0,6, 0,62, 0x80, 0x81, 0,6, 0,37, 
0,37, 0x90,58, 0x91,58, 0,87, 0,56, 0,6, 0,75, 0x80, 0x81, 0,25, 0,50, 0x90,58, 0x91,44, 0,68, 
0,18, 0,56, 0,6, 0,75, 0x80, 0,25, 0x81, 0,18, 0,31, 0x90,44, 0x91,44, 0,68, 0,75, 0,6, 
0,75, 0x81, 0,25, 0x80, 0,50, 0x90,44, 0x91,59, 0,137, 0,6, 0,6, 0,37, 0,37, 0x80, 0x81, 0,37, 
0,37, 0x90,58, 0x91,58, 0,106, 0,37, 0,6, 0,75, 0,6, 0x80, 0x81, 0,31, 0,37, 0x90,58, 0x91,52, 
0,62, 0,43, 0,37, 0,6, 0x91,44, 0,81, 0x80, 0,31, 0,37, 0x90,52, 0,62, 0,18, 0x81, 0,62, 
0x91,42, 0,6, 0x90,44, 0,68, 0,25, 0x81, 0,56, 0x91,56, 0,81, 0x80, 0,50, 0,12, 0x90,42, 0,6, 
0,6, 0,56, 0,6, 0x81, 0,50, 0x80, 0,31, 0x91,58, 0x90,58, 0,100, 0,43, 0,6, 0,62, 0,12, 
0x80, 0x81, 0,31, 0,43, 0x90,58, 0x91,44, 0,68, 0,31, 0,43, 0,6, 0,25, 0,50, 0x80, 0,43, 0x81, 
0,18, 0,12, 0x90,59, 0x91,44, 0,68, 0,75, 0,6, 0x90,59, 0,87, 0,31, 0x81, 0,31, 0x90,59, 0x91,59, 
0,143, 0,6, 0x90,59, 0,68, 0x81, 0,37, 0,43, 0x90,58, 0x91,58, 0,118, 0,25, 0,6, 0,68, 0x80, 
0x81, 0,37, 0,43, 0x90,58, 0x91,51, 0,68, 0,50, 0,12, 0,12, 0,6, 0,18, 0,43, 0x81, 0,6, 
0x80, 0,31, 0,50, 0x90,51, 0x91,51, 0,68, 0,6, 0,68, 0,6, 0,62, 0x80, 0x81, 0,6, 0,81, 0x90,58, 
0x91,59, 0,75, 0,62, 0,6, 0,6, 0,68, 0x80, 0x81, 0,81, 0x90,58, 0x91,58, 0,106, 0,37, 0,6, 
0,68, 0,18, 0x80, 0x81, 0,62, 0x90,44, 0x91,58, 0,100, 0,6, 0,37, 0,6, 0,12, 0,6, 0,68, 
0x81, 0,12, 0x80, 0,50, 0x90,44, 0x91,44, 0,100, 0,43, 0,6, 0,93, 0,6, 0x80, 0x81, 0,50, 0x90,58, 
0x91,59, 0,131, 0,6, 0,6, 0,6, 0,68, 0x81, 0,25, 0x80, 0,56, 0x90,58, 0x91,58, 0,93, 0,50, 
0,6, 0,68, 0x80, 0x81, 0,81, 0x90,56, 0x91,58, 0,87, 0,6, 0,31, 0,12, 0,6, 0,6, 0x90,59, 
0,68, 0x81, 0,81, 0x91,58, 0,81, 0,6, 0x80, 0,56, 0x90,42, 0,6, 0,62, 0x81, 0,6, 0x80, 0,81, 
0x91,58, 0x90,59, 0,81, 0,50, 0,6, 0,6, 0,6, 0,62, 0x81, 0,6, 0x80, 0,25, 0,56, 0x90,58, 
0x91,58, 0,75, 0,68, 0,6, 0,68, 0,6, 0,6, 0x80, 0x81, 0,68, 0x90,58, 0x91,56, 0,75, 0,62, 
0,6, 0,6, 0,81, 0x80, 0,25, 0x81, 0,43, 0x90,58, 0x91,56, 0,75, 0,68, 0,6, 0,75, 0x80, 0,12, 
0,18, 0x81, 0,43, 0x90,58, 0x91,59, 0,131, 0,6, 0,6, 0,6, 0,75, 0x80, 0x81, 0,31, 0,43, 0x90,58, 
0x91,58, 0,93, 0,50, 0,6, 0,75, 0x80, 0x81, 0,37, 0,37, 0x90,58, 0x91,52, 0,75, 0,18, 0,50, 
0,6, 0,75, 0x80, 0,6, 0x81, 0,18, 0,50, 0x90,52, 0x91,52, 0,68, 0,6, 0,68, 0,6, 0,56, 
0,25, 0x80, 0x81, 0,12, 0,56, 0x90,56, 0x91,56, 0,68, 0,75, 0,6, 0,6, 0,50, 0x80, 0x81, 0,25, 
0,25, 0,43, 0x90,58, 0x91,58, 0,87, 0,56, 0,6, 0,81, 0x80, 0x81, 0,12, 0,56, 0x90,58, 0x91,44, 
0,75, 0,12, 0,56, 0,6, 0,81, 0x80, 0,25, 0x81, 0,6, 0,37, 0x90,44, 0x91,44, 0,75, 0,68, 
0,68, 0,25, 0,18, 0x80, 0x81, 0,43, 0x90,59, 0x91,56, 0,137, 0,6, 0,6, 0,37, 0,25, 0x81, 0,6, 
0x80, 0,50, 0,31, 0x90,58, 0x91,59, 0,106, 0,37, 0,6, 0,68, 0x81, 0,18, 0x80, 0,12, 0,50, 0x90,58, 
0x91,52, 0,68, 0,37, 0,37, 0,6, 0,87, 0x80, 0x81, 0,62, 0x90,48, 0x91,52, 0,68, 0,75, 0,6, 
0,68, 0x80, 0,18, 0x81, 0,62, 0x90,48, 0x91,60, 0,131, 0,12, 0,6, 0,6, 0,62, 0x80, 0,6, 0x81, 
0,75, 0x90,59, 0x91,59, 0,106, 0,37, 0,6, 0,75, 0x80, 0x81, 0,75, 0x90,48, 0x91,59, 0,56, 0,50, 
0,37, 0,6, 0,25, 0,31, 0x80, 0,18, 0x81, 0,75, 0x90,48, 0x91,48, 0,56, 0,87, 0,6, 0,56, 
0x80, 0x81, 0,93, 0x90,48, 0x91,48, 0,143, 0,6, 0,43, 0,12, 0x80, 0x81, 0,93, 0x90,59, 0x91,59, 0,106, 
0,37, 0,6, 0,43, 0,6, 0x80, 0x81, 0,100, 0x90,52, 0x91,59, 0,31, 0,75, 0,25, 0,12, 0,6, 
0,18, 0,31, 0x81, 0,31, 0x80, 0,68, 0x90,52, 0x91,48, 0,31, 0,112, 0,6, 0,81, 0x80, 0,18, 0x81, 
0,50, 0x90,60, 0x91,48, 0,137, 0,6, 0,6, 0,68, 0x80, 0,31, 0x81, 0,50, 0x90,59, 0x91,59, 0,68, 
0,75, 0,6, 0,68, 0,18, 0x80, 0x81, 0,62, 0x90,48, 0x91,59, 0,68, 0,75, 0,6, 0,12, 0,6, 
0,68, 0x81, 0,18, 0x80, 0,43, 0x90,48, 0x91,48, 0,68, 0,75, 0,6, 0,81, 0x81, 0,25, 0x80, 0,43, 
0x90,48, 0x91,48, 0,131, 0,6, 0,6, 0,6, 0,50, 0,31, 0x80, 0x81, 0,68, 0x90,59, 0x91,59, 0,93, 
0,50, 0,6, 0,50, 0,25, 0x80, 0x81, 0,75, 0x90,52, 0x91,59, 0,56, 0,37, 0,31, 0,12, 0,6, 
0,6, 0,68, 0x80, 0,6, 0x81, 0,75, 0x90,52, 0x91,48, 0,56, 0,87, 0,6, 0,56, 0x81, 0,12, 0x80, 
0,81, 0x90,59, 0x91,48, 0,131, 0,6, 0,6, 0,6, 0,56, 0x80, 0x81, 0,25, 0,68, 0x90,57, 0x91,57, 
0,93, 0,50, 0,6, 0,56, 0,25, 0x80, 0x81, 0,18, 0,50, 0x90,57, 0x91,52, 0,75, 0,18, 0,43, 
0,6, 0,6, 0,81, 0x80, 0,18, 0,12, 0x81, 0,37, 0x90,52, 0x91,47, 0,75, 0,68, 0,6, 0,81, 
0,6, 0x81, 0,25, 0x80, 0,37, 0x90,47, 0x91,59, 0,131, 0,6, 0,6, 0,6, 0,62, 0x81, 0,25, 0x80, 
0,18, 0,43, 0x90,57, 0x91,57, 0,125, 0,18, 0,6, 0,62, 0,18, 0x80, 0x81, 0,18, 0,50, 0x90,57, 
0x91,52, 0,68, 0,56, 0,18, 0,6, 0,62, 0x81, 0,18, 0x80, 0,31, 0,37, 0x90,52, 0x91,52, 0,68, 
0,6, 0,68, 0,6, 0,62, 0x80, 0x81, 0,6, 0,25, 0,56, 0x90,57, 0x91,57, 0,75, 0,68, 0,6, 
0,6, 0,62, 0x80, 0x81, 0,6, 0,37, 0,37, 0x90,57, 0x91,57, 0,87, 0,56, 0,6, 0,75, 0x80, 0x81, 
0,25, 0,50, 0x90,57, 0x91,48, 0,68, 0,18, 0,56, 0,6, 0,75, 0x80, 0,25, 0x81, 0,18, 0,31, 
0x90,48, 0x91,47, 0,68, 0,75, 0,6, 0,75, 0x81, 0,25, 0x80, 0,50, 0x90,47, 0x91,59, 0,137, 0,6, 
0,6, 0,37, 0,37, 0x80, 0x81, 0,37, 0,37, 0x90,57, 0x91,57, 0,106, 0,37, 0,6, 0,75, 0,6, 
0x80, 0x81, 0,31, 0,37, 0x90,57, 0x91,45, 0,62, 0,43, 0,37, 0,6, 0,62, 0x81, 0,18, 0x80, 0,31, 
0,37, 0x90,45, 0x91,45, 0,62, 0,18, 0,62, 0,6, 0,62, 0x80, 0x81, 0,6, 0,25, 0,56, 0x90,57, 
0x91,57, 0,81, 0,50, 0,12, 0,6, 0,6, 0,56, 0,6, 0x80, 0x81, 0,50, 0,31, 0x90,57, 0x91,57, 
0,100, 0,43, 0,6, 0,62, 0,12, 0x80, 0x81, 0,31, 0,43, 0x90,57, 0x91,47, 0,68, 0,31, 0,43, 
0,6, 0,25, 0,50, 0x80, 0,43, 0x81, 0,18, 0,12, 0x90,52, 0x91,47, 0,68, 0,75, 0,6, 0,81, 
0x80, 0,6, 0,31, 0x81, 0,31, 0x90,52, 0x91,59, 0,143, 0,6, 0,68, 0x81, 0,12, 0x80, 0,25, 0,43, 
0x90,57, 0x91,57, 0,118, 0,25, 0,6, 0,68, 0x80, 0x81, 0,37, 0,43, 0x90,57, 0x91,50, 0,68, 0,50, 
0,12, 0,12, 0,6, 0,18, 0,43, 0x81, 0,6, 0x80, 0,31, 0,50, 0x90,50, 0x91,50, 0,68, 0,6, 
0,68, 0,6, 0,62, 0x80, 0x81, 0,6, 0,81, 0x90,57, 0x91,59, 0,75, 0,62, 0,6, 0,6, 0,68, 
0x80, 0x81, 0,81, 0x90,57, 0x91,57, 0,106, 0,37, 0,6, 0,68, 0,18, 0x80, 0x81, 0,62, 0x90,47, 0x91,57, 
0,100, 0,6, 0,37, 0,6, 0,12, 0,6, 0,68, 0x81, 0,12, 0x80, 0,50, 0x90,47, 0x91,47, 0,100, 
0,43, 0,6, 0,93, 0,6, 0x80, 0x81, 0,50, 0x90,57, 0x91,59, 0,131, 0,6, 0,6, 0,6, 0,68, 
0x81, 0,25, 0x80, 0,56, 0x90,57, 0x91,57, 0,93, 0,50, 0,6, 0,68, 0x80, 0x81, 0,81, 0x90,52, 0x91,57, 
0,87, 0,6, 0,31, 0,12, 0,6, 0,6, 0,68, 0x81, 0,18, 0x80, 0,62, 0x90,57, 0x91,52, 0,81, 
0,6, 0,56, 0,6, 0,62, 0x80, 0,6, 0,18, 0x81, 0,62, 0x90,57, 0x91,59, 0,81, 0,50, 0,6, 
0,6, 0,6, 0,62, 0x80, 0,6, 0x81, 0,25, 0,56, 0x90,57, 0x91,57, 0,75, 0,68, 0,6, 0,68, 
0,6, 0,6, 0x80, 0x81, 0,68, 0x90,57, 0x91,52, 0,75, 0,62, 0,6, 0,6, 0,81, 0x80, 0,25, 0x81, 
0,43, 0x90,57, 0x91,52, 0,75, 0,68, 0,6, 0,75, 0x80, 0,12, 0,18, 0x81, 0,43, 0x90,57, 0x91,59, 
0,131, 0,6, 0,6, 0,6, 0,75, 0x80, 0x81, 0,31, 0,43, 0x90,57, 0x91,57, 0,93, 0,50, 0,6, 
0,75, 0x80, 0x81, 0,37, 0,37, 0x90,57, 0x91,52, 0,75, 0,18, 0,50, 0,6, 0,75, 0x80, 0,6, 0x81, 
0,18, 0,50, 0x90,52, 0x91,52, 0,68, 0,6, 0,68, 0,6, 0,56, 0,25, 0x80, 0x81, 0,12, 0,56, 
0x90,57, 0x91,57, 0,68, 0,75, 0,6, 0,6, 0,50, 0x80, 0x81, 0,25, 0,25, 0,43, 0x90,57, 0x91,57, 
0,87, 0,56, 0,6, 0,81, 0x80, 0x81, 0,12, 0,56, 0x90,57, 0x91,47, 0,75, 0,12, 0,56, 0,6, 
0,81, 0x80, 0,25, 0x81, 0,6, 0,37, 0x90,47, 0x91,47, 0,75, 0,68, 0,68, 0,25, 0,18, 0x80, 0x81, 
0,43, 0x90,59, 0x91,57, 0,137, 0,6, 0,6, 0,37, 0,25, 0x81, 0,6, 0x80, 0,50, 0,31, 0x90,57, 
0x91,59, 0,106, 0,37, 0,6, 0,68, 0x81, 0,18, 0x80, 0,12, 0,50, 0x90,57, 0x91,52, 0,68, 0,37, 
0,37, 0x90,36, 0x81, 0,156, 0x91,48, 0,143, 0x90,24, 0,6, 0,68, 0x81, 0,81, 0x91,48, 0,131, 0x80, 0,12, 
0x90,48, 0,6, 0,6, 0,62, 0x81, 0,6, 0,68, 0x90,53, 0x91,53, 0,6, 0,106, 0,37, 0x91,24, 0x90,48, 
0,6, 0,75, 0,68, 0x90,53, 0,6, 0,56, 0,50, 0,37, 0x90,24, 0,6, 0,25, 0x81, 0,31, 0,18, 
0,68, 0x91,55, 0,6, 0,56, 0,87, 0x91,24, 0x90,24, 0,6, 0,56, 0,87, 0,6, 0,143, 0,6, 
0x91,55, 0x90,55, 0,43, 0,12, 0,87, 0,6, 0,106, 0x80, 0x81, 0,37, 0x90,24, 0x91,24, 0,6, 0,43, 
0,6, 0,93, 0,6, 0,31, 0,75, 0,25, 0x80, 0x81, 0,12, 0x90,24, 0x91,60, 0,6, 0,18, 0,31, 
0,31, 0,62, 0x91,65, 0,6, 0,31, 0,112, 0x90,24, 0x91,60, 0,6, 0,81, 0,18, 0,43, 0x91,65, 
0,6, 0,137, 0x80, 0,6, 0x90,24, 0x91,65, 0,6, 0,68, 0,31, 0,43, 0x91,67, 0,6, 0,68, 0,75, 
0x91,24, 0x90,24, 0,6, 0,68, 0,18, 0,56, 0,6, 0,68, 0,75, 0,6, 0,12, 0,6, 0x80, 0x81, 
0,68, 0,18, 0,37, 0x90,72, 0x91,77, 0,6, 0,68, 0,75, 0x90,24, 0x91,67, 0,6, 0,81, 0,25, 
0,37, 0x91,72, 0,6, 0,131, 0,6, 0x80, 0,6, 0x90,24, 0x91,72, 0,6, 0,50, 0,31, 0,62, 0x91,77, 
0,6, 0,93, 0,50, 0x91,24, 0x90,24, 0,6, 0,50, 0,25, 0,68, 0,6, 0,56, 0,37, 0,31, 
0,12, 0x80, 0x81, 0,6, 0x90,24, 0x91,79, 0,6, 0,68, 0,6, 0,68, 0x91,80, 0,6, 0,56, 0,87, 
0x91,42, 0x90,42, 0,6, 0,56, 0,12, 0x80, 0x81, 0,75, 0x90,77, 0x91,77, 0,6, 0,81, 0,50, 0,6, 
0,6, 0x90,42, 0x91,73, 0,6, 0,56, 0,25, 0x80, 0,62, 0x91,80, 0x90,77, 0,6, 0,81, 0,12, 0,50, 
0x90,24, 0x91,73, 0,6, 0,56, 0,25, 0,18, 0,43, 0x91,77, 0,6, 0,75, 0,18, 0,43, 0x80, 0,6, 
0x90,42, 0x91,73, 0,6, 0,81, 0,18, 0x80, 0,12, 0,31, 0x91,69, 0x90,77, 0,6, 0,75, 0,68, 0x90,24, 
0x91,68, 0,6, 0,81, 0,6, 0,25, 0,31, 0x91,65, 0,6, 0,131, 0,6, 0x80, 0,6, 0x90,42, 0x91,24, 
0,6, 0,62, 0,25, 0,18, 0x80, 0,37, 0x90,68, 0,6, 0,125, 0,18, 0x91,42, 0x90,24, 0,6, 0,62, 
0,18, 0,18, 0x81, 0,43, 0x91,61, 0,6, 0,68, 0,56, 0,18, 0x91,57, 0x90,36, 0,6, 0,62, 0,18, 
0,31, 0,31, 0x91,66, 0,6, 0,68, 0,6, 0,68, 0x90,42, 0x91,24, 0,6, 0,62, 0,6, 0,25, 
0x80, 0,50, 0x90,61, 0,6, 0,75, 0,68, 0x90,57, 0,6, 0,6, 0x81, 0,62, 0,6, 0,37, 0,31, 
0x90,56, 0x91,61, 0,6, 0,87, 0,56, 0x90,24, 0x91,54, 0,6, 0,75, 0,25, 0,43, 0x91,49, 0,6, 
0,68, 0,18, 0,56, 0x91,54, 0,6, 0x90,60, 0,75, 0,25, 0,18, 0,25, 0x91,56, 0,6, 0,68, 
0x80, 0,75, 0x90,42, 0x91,24, 0,6, 0,75, 0,25, 0x80, 0,43, 0x90,56, 0,6, 0,137, 0x81, 0,6, 0x90,42, 
0x91,24, 0,6, 0,37, 0,37, 0,37, 0x80, 0,31, 0x90,69, 0,6, 0,106, 0,37, 0x91,42, 0x90,24, 0,6, 
0,75, 0,6, 0,31, 0x81, 0,31, 0x91,61, 0,6, 0,62, 0,43, 0,37, 0x91,48, 0x90,36, 0,6, 0,62, 
0,18, 0,31, 0,31, 0x91,53, 0,6, 0,62, 0,18, 0,62, 0x90,42, 0x91,24, 0,6, 0,62, 0,6, 
0,25, 0x80, 0,50, 0x90,60, 0,6, 0,81, 0,50, 0x81, 0,12, 0x91,42, 0x90,53, 0,6, 0,6, 0,56, 
0,6, 0,50, 0x81, 0,25, 0x90,55, 0x91,60, 0,6, 0,100, 0,43, 0x90,24, 0x91,53, 0,6, 0,62, 0,12, 
0,31, 0,37, 0x91,65, 0,6, 0,68, 0,31, 0,43, 0x91,60, 0,6, 0,25, 0x80, 0,50, 0,43, 0,18, 
0,6, 0x91,60, 0x90,65, 0,6, 0,68, 0,75, 0x90,24, 0x91,65, 0,6, 0,81, 0,6, 0,31, 0,25, 
0x91,60, 0,6, 0,143, 0x91,42, 0,6, 0x90,55, 0,68, 0,12, 0,25, 0x81, 0,37, 0x91,65, 0,6, 0,118, 
0x80, 0,25, 0x90,42, 0x91,24, 0,6, 0,68, 0,37, 0x80, 0,37, 0x90,72, 0,6, 0,68, 0,50, 0,12, 
0x81, 0,12, 0x91,42, 0x90,67, 0,6, 0,18, 0,43, 0,6, 0,31, 0x81, 0,43, 0x90,79, 0x91,72, 0,6, 
0,68, 0,6, 0,68, 0x90,24, 0x91,67, 0,6, 0,62, 0,6, 0,75, 0x91,72, 0,6, 0,75, 0,62, 
0x80, 0,6, 0x90,24, 0x91,67, 0,6, 0,68, 0,75, 0x91,72, 0,6, 0,106, 0,37, 0x91,24, 0x90,24, 0,6, 
0,68, 0,18, 0,56, 0,6, 0,100, 0,6, 0,37, 0,6, 0,12, 0,6, 0x80, 0x81, 0,68, 0,12, 
0,43, 0x90,77, 0x91,67, 0,6, 0,100, 0,43, 0x90,24, 0x91,72, 0,6, 0,93, 0,6, 0,43, 0x91,77, 
0,6, 0,131, 0,6, 0x80, 0,6, 0x90,24, 0x91,77, 0,6, 0,68, 0,25, 0,50, 0x91,79, 0,6, 0,93, 
0,50, 0x91,24, 0x90,24, 0,6, 0,68, 0,75, 0,6, 0,87, 0,6, 0,31, 0,12, 0x80, 0x81, 0,6, 
0x90,24, 0x91,84, 0,6, 0,68, 0,18, 0,56, 0x91,85, 0,6, 0,81, 0,6, 0,56, 0x90,42, 0x91,24, 
0,6, 0,62, 0,6, 0x80, 0,18, 0,56, 0x90,79, 0,6, 0,81, 0,50, 0,6, 0x81, 0,6, 0x90,42, 
0x91,24, 0,6, 0,62, 0,6, 0,25, 0x80, 0,50, 0x90,80, 0,6, 0,75, 0,68, 0x91,42, 0x90,24, 0,6, 
0,68, 0,6, 0x81, 0,6, 0,62, 0x91,77, 0,6, 0,75, 0,62, 0x80, 0,6, 0x90,42, 0x91,79, 0,6, 
0,81, 0x80, 0,25, 0,37, 0x91,77, 0x90,79, 0,6, 0,75, 0,68, 0x91,42, 0x90,24, 0,6, 0,75, 0,12, 
0x81, 0,18, 0,37, 0x91,73, 0,6, 0,131, 0,6, 0x80, 0,6, 0x90,42, 0x91,24, 0,6, 0,75, 0,31, 
0x80, 0,37, 0x90,77, 0,6, 0,93, 0,50, 0x91,42, 0x90,24, 0,6, 0,75, 0,37, 0x81, 0,31, 0x91,69, 
0,6, 0,75, 0,18, 0,50, 0x91,73, 0x90,36, 0,6, 0,75, 0,6, 0,18, 0,43, 0x91,69, 0,6, 
0,68, 0,6, 0,68, 0x90,42, 0x91,24, 0,6, 0,56, 0,25, 0,12, 0x80, 0,50, 0x90,65, 0,6, 0,68, 
0,75, 0x90,68, 0,6, 0,6, 0x81, 0,50, 0,25, 0,25, 0,37, 0x90,68, 0x91,65, 0,6, 0,87, 0,56, 
0x90,24, 0x91,65, 0,6, 0,81, 0,12, 0,50, 0x91,61, 0,6, 0,75, 0,12, 0,56, 0x91,57, 0,6, 
0x90,60, 0,81, 0,25, 0,6, 0,31, 0x91,61, 0,6, 0,75, 0x80, 0,68, 0x90,42, 0x91,24, 0,68, 0,25, 
0x80, 0,18, 0,37, 0x90,61, 0,6, 0,137, 0x81, 0,6, 0x90,42, 0x91,24, 0,6, 0,37, 0,25, 0,6, 
0,50, 0x80, 0,25, 0x90,56, 0,6, 0,106, 0,37, 0x91,42, 0x90,24, 0,6, 0,68, 0,18, 0,12, 0x81, 
0,43, 0x91,49, 0,6, 0,68, 0,37, 0,37, 0x91,54, 0x90,32, 0,6, 0,87, 0,56, 0x91,49, 0,6, 
0,68, 0,75, 0x91,20, 0x90,20, 0,6, 0,68, 0,18, 0,62, 0,131, 0x80, 0x81, 0,12, 0x90,20, 0x91,32, 
0,6, 0,6, 0,62, 0,6, 0,75, 0,106, 0,37, 0x90,20, 0x91,32, 0,6, 0,75, 0,75, 0,56, 
0,50, 0,37, 0,6, 0,25, 0x80, 0x81, 0,31, 0,18, 0,75, 0x90,44, 0x91,44, 0,56, 0,87, 0,6, 
0,56, 0x80, 0x81, 0,93, 0x90,44, 0x91,44, 0,143, 0,6, 0,43, 0,12, 0x80, 0x81, 0,93, 0x90,58, 0x91,58, 
0,106, 0,37, 0,6, 0,43, 0,6, 0x80, 0x81, 0,100, 0x90,51, 0x91,58, 0,31, 0,75, 0,25, 0,12, 
0,6, 0,18, 0,31, 0x81, 0,31, 0x80, 0,68, 0x90,51, 0x91,44, 0,31, 0,112, 0,6, 0,81, 0x80, 0,18, 
0x81, 0,50, 0x90,59, 0x91,44, 0,137, 0,6, 0,6, 0,68, 0x80, 0,31, 0x81, 0,50, 0x90,58, 0x91,58, 0,68, 
0,75, 0,6, 0,68, 0,18, 0x80, 0x81, 0,62, 0x90,44, 0x91,58, 0,68, 0,75, 0,6, 0,12, 0,6, 
0,68, 0x81, 0,18, 0x80, 0,43, 0x90,44, 0x91,44, 0,68, 0,75, 0,6, 0,81, 0x81, 0,25, 0x80, 0,43, 
0x90,44, 0x91,44, 0,131, 0,6, 0,6, 0,6, 0,50, 0,31, 0x80, 0x81, 0,68, 0x90,58, 0x91,58, 0,93, 
0,50, 0,6, 0,50, 0,25, 0x80, 0x81, 0,75, 0x90,51, 0x91,58, 0,56, 0,37, 0,31, 0,12, 0,6, 
0,6, 0,68, 0x80, 0,6, 0x81, 0,75, 0x90,51, 0x91,44, 0,56, 0,87, 0,6, 0,56, 0x81, 0,12, 0x80, 
0,81, 0x90,59, 0x91,44, 0,131, 0,6, 0,6, 0,6, 0,56, 0x80, 0x81, 0,25, 0,68, 0x90,58, 0x91,58, 
0,93, 0,50, 0,6, 0,56, 0,25, 0x80, 0x81, 0,18, 0,50, 0x90,58, 0x91,52, 0,75, 0,18, 0,43, 
0,6, 0,6, 0,81, 0x80, 0,18, 0,12, 0x81, 0,37, 0x90,52, 0x91,44, 0,75, 0,68, 0,6, 0,81, 
0,6, 0x81, 0,25, 0x80, 0,37, 0x90,44, 0x91,59, 0,131, 0,6, 0,6, 0,6, 0,62, 0x81, 0,25, 0x80, 
0,18, 0,43, 0x90,58, 0x91,58, 0,125, 0,18, 0,6, 0,62, 0,18, 0x80, 0x81, 0,18, 0,50, 0x90,58, 
0x91,52, 0,68, 0,56, 0,18, 0,6, 0,62, 0x81, 0,18, 0x80, 0,31, 0,37, 0x90,52, 0x91,52, 0,68, 
0,6, 0,68, 0,6, 0,62, 0x80, 0x81, 0,6, 0,25, 0,56, 0x90,56, 0x91,56, 0,75, 0,68, 0,6, 
0,6, 0,62, 0x80, 0x81, 0,6, 0,37, 0,37, 0x90,58, 0x91,58, 0,87, 0,56, 0,6, 0,75, 0x80, 0x81, 
0,25, 0,50, 0x90,58, 0x91,44, 0,68, 0,18, 0,56, 0,6, 0,75, 0x80, 0,25, 0x81, 0,18, 0,31, 
0x90,44, 0x91,44, 0,68, 0,75, 0,6, 0,75, 0x81, 0,25, 0x80, 0,50, 0x90,44, 0x91,59, 0,137, 0,6, 
0,6, 0,37, 0,37, 0x80, 0x81, 0,37, 0,37, 0x90,58, 0x91,58, 0,106, 0,37, 0,6, 0,75, 0,6, 
0x80, 0x81, 0,31, 0,37, 0x90,58, 0x91,52, 0,62, 0,43, 0,37, 0,6, 0x91,44, 0,81, 0x80, 0,31, 0,37, 
0x90,52, 0,62, 0,18, 0x81, 0,62, 0x91,42, 0,6, 0x90,44, 0,68, 0,25, 0x81, 0,56, 0x91,56, 0,81, 
0x80, 0,50, 0,12, 0x90,42, 0,6, 0,6, 0,56, 0,6, 0x81, 0,50, 0x80, 0,31, 0x91,58, 0x90,58, 0,100, 
0,43, 0,6, 0,62, 0,12, 0x80, 0x81, 0,31, 0,43, 0x90,58, 0x91,44, 0,68, 0,31, 0,43, 0,6, 
0,25, 0,50, 0x80, 0,43, 0x81, 0,18, 0,12, 0x90,59, 0x91,44, 0,68, 0,75, 0,6, 0x90,59, 0,87, 
0,31, 0x81, 0,31, 0x90,59, 0x91,59, 0,143, 0,6, 0x90,59, 0,68, 0x81, 0,37, 0,43, 0x90,58, 0x91,58, 
0,118, 0,25, 0,6, 0,68, 0x80, 0x81, 0,37, 0,43, 0x90,58, 0x91,51, 0,68, 0,50, 0,12, 0,12, 
0,6, 0,18, 0,43, 0x81, 0,6, 0x80, 0,31, 0,50, 0x90,51, 0x91,51, 0,68, 0,6, 0,68, 0,6, 
0,62, 0x80, 0x81, 0,6, 0,81, 0x90,58, 0x91,59, 0,75, 0,62, 0,6, 0,6, 0,68, 0x80, 0x81, 0,81, 
0x90,58, 0x91,58, 0,106, 0,37, 0,6, 0,68, 0,18, 0x80, 0x81, 0,62, 0x90,44, 0x91,58, 0,100, 0,6, 
0,37, 0,6, 0,12, 0,6, 0,68, 0x81, 0,12, 0x80, 0,50, 0x90,44, 0x91,44, 0,100, 0,43, 0,6, 
0,93, 0,6, 0x80, 0x81, 0,50, 0x90,58, 0x91,59, 0,131, 0,6, 0,6, 0,6, 0,68, 0x81, 0,25, 0x80, 
0,56, 0x90,58, 0x91,58, 0,93, 0,50, 0,6, 0,68, 0x80, 0x81, 0,81, 0x90,56, 0x91,58, 0,87, 0,6, 
0,31, 0,12, 0,6, 0,6, 0x90,59, 0,68, 0x81, 0,81, 0x91,58, 0,81, 0,6, 0x80, 0,56, 0x90,42, 
0,6, 0,62, 0x81, 0,6, 0x80, 0,81, 0x91,58, 0x90,59, 0,81, 0,50, 0,6, 0,6, 0,6, 0,62, 
0x81, 0,6, 0x80, 0,25, 0,56, 0x90,58, 0x91,58, 0,75, 0,68, 0,6, 0,68, 0,6, 0,6, 0x80, 0x81, 
0,68, 0x90,58, 0x91,56, 0,75, 0,62, 0,6, 0,6, 0,81, 0x80, 0,25, 0x81, 0,43, 0x90,58, 0x91,56, 
0,75, 0,68, 0,6, 0,75, 0x80, 0,12, 0,18, 0x81, 0,43, 0x90,58, 0x91,59, 0,131, 0,6, 0,6, 
0,6, 0,75, 0x80, 0x81, 0,31, 0,43, 0x90,58, 0x91,58, 0,93, 0,50, 0,6, 0,75, 0x80, 0x81, 0,37, 
0,37, 0x90,58, 0x91,52, 0,75, 0,18, 0,50, 0,6, 0,75, 0x80, 0,6, 0x81, 0,18, 0,50, 0x90,52, 
0x91,52, 0,68, 0,6, 0,68, 0,6, 0,56, 0,25, 0x80, 0x81, 0,12, 0,56, 0x90,56, 0x91,56, 0,68, 
0,75, 0,6, 0,6, 0,50, 0x80, 0x81, 0,25, 0,25, 0,43, 0x90,58, 0x91,58, 0,87, 0,56, 0,6, 
0,81, 0x80, 0x81, 0,12, 0,56, 0x90,58, 0x91,44, 0,75, 0,12, 0,56, 0,6, 0,81, 0x80, 0,25, 0x81, 
0,6, 0,37, 0x90,44, 0x91,44, 0,75, 0,68, 0,68, 0,25, 0,18, 0x80, 0x81, 0,43, 0x90,59, 0x91,56, 
0,137, 0,6, 0,6, 0,37, 0,25, 0x81, 0,6, 0x80, 0,50, 0,31, 0x90,58, 0x91,59, 0,106, 0,37, 
0,6, 0,68, 0x81, 0,18, 0x80, 0,12, 0,50, 0x90,58, 0x91,52, 0,68, 0,37, 0,37, 0,6, 0,87, 
0x80, 0x81, 0,62, 0x90,48, 0x91,52, 0,68, 0,75, 0,6, 0,68, 0x80, 0,18, 0x81, 0,62, 0x90,48, 0x91,60, 
0,131, 0,12, 0,6, 0,6, 0,62, 0x80, 0,6, 0x81, 0,75, 0x90,59, 0x91,59, 0,106, 0,37, 0,6, 
0,75, 0x80, 0x81, 0,75, 0x90,48, 0x91,59, 0,56, 0,50, 0,37, 0,6, 0,25, 0,31, 0x80, 0,18, 0x81, 
0,75, 0x90,48, 0x91,48, 0,56, 0,87, 0,6, 0,56, 0x80, 0x81, 0,93, 0x90,48, 0x91,48, 0,143, 0,6, 
0,43, 0,12, 0x80, 0x81, 0,93, 0x90,59, 0x91,59, 0,106, 0,37, 0,6, 0,43, 0,6, 0x80, 0x81, 0,100, 
0x90,52, 0x91,59, 0,31, 0,75, 0,25, 0,12, 0,6, 0,18, 0,31, 0x81, 0,31, 0x80, 0,68, 0x90,52, 
0x91,48, 0,31, 0,112, 0,6, 0,81, 0x80, 0,18, 0x81, 0,50, 0x90,60, 0x91,48, 0,137, 0,6, 0,6, 
0,68, 0x80, 0,31, 0x81, 0,50, 0x90,59, 0x91,59, 0,68, 0,75, 0,6, 0,68, 0,18, 0x80, 0x81, 0,62, 
0x90,48, 0x91,59, 0,68, 0,75, 0,6, 0,12, 0,6, 0,68, 0x81, 0,18, 0x80, 0,43, 0x90,48, 0x91,48, 
0,68, 0,75, 0,6, 0,81, 0x81, 0,25, 0x80, 0,43, 0x90,48, 0x91,48, 0,131, 0,6, 0,6, 0,6, 
0,50, 0,31, 0x80, 0x81, 0,68, 0x90,59, 0x91,59, 0,93, 0,50, 0,6, 0,50, 0,25, 0x80, 0x81, 0,75, 
0x90,52, 0x91,59, 0,56, 0,37, 0,31, 0,12, 0,6, 0,6, 0,68, 0x80, 0,6, 0x81, 0,75, 0x90,52, 
0x91,48, 0,56, 0,87, 0,6, 0,56, 0x81, 0,12, 0x80, 0,81, 0x90,59, 0x91,48, 0,131, 0,6, 0,6, 
0,6, 0,56, 0x80, 0x81, 0,25, 0,68, 0x90,57, 0x91,57, 0,93, 0,50, 0,6, 0,56, 0,25, 0x80, 0x81, 
0,18, 0,50, 0x90,57, 0x91,52, 0,75, 0,18, 0,43, 0,6, 0,6, 0,81, 0x80, 0,18, 0,12, 0x81, 
0,37, 0x90,52, 0x91,47, 0,75, 0,68, 0,6, 0,81, 0,6, 0x81, 0,25, 0x80, 0,37, 0x90,47, 0x91,59, 
0,131, 0,6, 0,6, 0,6, 0,62, 0x81, 0,25, 0x80, 0,18, 0,43, 0x90,57, 0x91,57, 0,125, 0,18, 
0,6, 0,62, 0,18, 0x80, 0x81, 0,18, 0,50, 0x90,57, 0x91,52, 0,68, 0,56, 0,18, 0,6, 0,62, 
0x81, 0,18, 0x80, 0,31, 0,37, 0x90,52, 0x91,52, 0,68, 0,6, 0,68, 0,6, 0,62, 0x80, 0x81, 0,6, 
0,25, 0,56, 0x90,57, 0x91,57, 0,75, 0,68, 0,6, 0,6, 0,62, 0x80, 0x81, 0,6, 0,37, 0,37, 
0x90,57, 0x91,57, 0,87, 0,56, 0,6, 0,75, 0x80, 0x81, 0,25, 0,50, 0x90,57, 0x91,48, 0,68, 0,18, 
0,56, 0,6, 0,75, 0x80, 0,25, 0x81, 0,18, 0,31, 0x90,48, 0x91,47, 0,68, 0,75, 0,6, 0,75, 
0x81, 0,25, 0x80, 0,50, 0x90,47, 0x91,59, 0,137, 0,6, 0,6, 0,37, 0,37, 0x80, 0x81, 0,37, 0,37, 
0x90,57, 0x91,57, 0,106, 0,37, 0,6, 0,75, 0,6, 0x80, 0x81, 0,31, 0,37, 0x90,57, 0x91,45, 0,62, 
0,43, 0,37, 0,6, 0,62, 0x81, 0,18, 0x80, 0,31, 0,37, 0x90,45, 0x91,45, 0,62, 0,18, 0,62, 
0,6, 0,62, 0x80, 0x81, 0,6, 0,25, 0,56, 0x90,57, 0x91,57, 0,81, 0,50, 0,12, 0,6, 0,6, 
0,56, 0,6, 0x80, 0x81, 0,50, 0,31, 0x90,57, 0x91,57, 0,100, 0,43, 0,6, 0,62, 0,12, 0x80, 0x81, 
0,31, 0,43, 0x90,57, 0x91,47, 0,68, 0,31, 0,43, 0,6, 0,25, 0,50, 0x80, 0,43, 0x81, 0,18, 
0,12, 0x90,52, 0x91,47, 0,68, 0,75, 0,6, 0,81, 0x80, 0,6, 0,31, 0x81, 0,31, 0x90,52, 0x91,59, 
0,143, 0,6, 0,68, 0x81, 0,12, 0x80, 0,25, 0,43, 0x90,57, 0x91,57, 0,118, 0,25, 0,6, 0,68, 
0x80, 0x81, 0,37, 0,43, 0x90,57, 0x91,50, 0,68, 0,50, 0,12, 0,12, 0,6, 0,18, 0,43, 0x81, 0,6, 
0x80, 0,31, 0,50, 0x90,50, 0x91,50, 0,68, 0,6, 0,68, 0,6, 0,62, 0x80, 0x81, 0,6, 0,81, 0x90,57, 
0x91,59, 0,75, 0,62, 0,6, 0,6, 0,68, 0x80, 0x81, 0,81, 0x90,57, 0x91,57, 0,106, 0,37, 0,6, 
0,68, 0,18, 0x80, 0x81, 0,62, 0x90,47, 0x91,57, 0,100, 0,6, 0,37, 0,6, 0,12, 0,6, 0,68, 
0x81, 0,12, 0x80, 0,50, 0x90,47, 0x91,47, 0,100, 0,43, 0,6, 0,93, 0,6, 0x80, 0x81, 0,50, 0x90,57, 
0x91,59, 0,131, 0,6, 0,6, 0,6, 0,68, 0x81, 0,25, 0x80, 0,56, 0x90,57, 0x91,57, 0,93, 0,50, 
0,6, 0,68, 0x80, 0x81, 0,81, 0x90,52, 0x91,57, 0,87, 0,6, 0,31, 0,12, 0,6, 0,6, 0,68, 
0x81, 0,18, 0x80, 0,62, 0x90,57, 0x91,52, 0,81, 0,6, 0,56, 0,6, 0,62, 0x80, 0,6, 0,18, 0x81, 
0,62, 0x90,57, 0x91,59, 0,81, 0,50, 0,6, 0,6, 0,6, 0,62, 0x80, 0,6, 0x81, 0,25, 0,56, 
0x90,57, 0x91,57, 0,75, 0,68, 0,6, 0,68, 0,6, 0,6, 0x80, 0x81, 0,68, 0x90,57, 0x91,52, 0,75, 
0,62, 0,6, 0,6, 0,81, 0x80, 0,25, 0x81, 0,43, 0x90,57, 0x91,52, 0,75, 0,68, 0,6, 0,75, 
0x80, 0,12, 0,18, 0x81, 0,43, 0x90,57, 0x91,59, 0,131, 0,6, 0,6, 0,6, 0,75, 0x80, 0x81, 0,31, 
0,43, 0x90,57, 0x91,57, 0,93, 0,50, 0,6, 0,75, 0x80, 0x81, 0,37, 0,37, 0x90,57, 0x91,52, 0,75, 
0,18, 0,50, 0,6, 0,75, 0x80, 0,6, 0x81, 0,18, 0,50, 0x90,52, 0x91,52, 0,68, 0,6, 0,68, 
0,6, 0,56, 0,25, 0x80, 0x81, 0,12, 0,56, 0x90,57, 0x91,57, 0,68, 0,75, 0,6, 0,6, 0,50, 
0x80, 0x81, 0,25, 0,25, 0,43, 0x90,57, 0x91,57, 0,87, 0,56, 0,6, 0,81, 0x80, 0x81, 0,12, 0,56, 
0x90,57, 0x91,47, 0,75, 0,12, 0,56, 0,6, 0,81, 0x80, 0,25, 0x81, 0,6, 0,37, 0x90,47, 0x91,47, 
0,75, 0,68, 0,68, 0,25, 0,18, 0x80, 0x81, 0,43, 0x90,59, 0x91,57, 0,137, 0,6, 0,6, 0,37, 
0,25, 0x81, 0,6, 0x80, 0,50, 0,31, 0x90,57, 0x91,59, 0,106, 0,37, 0,6, 0,68, 0x81, 0,18, 0x80, 
0,12, 0,50, 0x90,57, 0x91,52, 0,68, 0,37, 0,37, 0x80, 0x81, 0xf0};


void StartMusic(Game_t * game)
{
  if (!game->ab.tunes.playing())
    game->ab.tunes.playScore(score);
  game->settings.sound = true;
}


void StopMusic(Game_t * game)
{
  if (game->ab.tunes.playing())
    game->ab.tunes.stopScore();
  game->settings.sound = false; 
}

