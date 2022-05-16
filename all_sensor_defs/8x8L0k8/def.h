#ifndef _def_H
#define _def_H

// DEVICE ADRESS
#define  SENSOR_ADDRESS          0x1A
#define  EEPROM_ADDRESS          0x1B

// I2C CLOCK
#define CLOCK_SENSOR            1000000
#define CLOCK_EEPROM            400000

// SETTING
#define PTAT_BUFFER_SIZE 10
#define VDD_BUFFER_SIZE 10
#define ELOFFSETS_BUFFER_SIZE 10
#define ELOFFSETS_FILTER_START_DELAY  10
#define START_WITH_BLOCK 1 // start with electrical offsets
#define READ_ELOFFSET_EVERYX 10
#define TIMER_OFFSET 0

// WIFI SETTING
#define UDP_PACKET_LENGTH 262
#define ACCESSPOINTNAME "HTPAd8x8L0k8"
#define ACCESSPOINTKEY "heimannsensor"

// PARAMETER LOOKUPTABLE
#define TABLENUMBER 96      // table number of this sensor type
#define PCSCALEVAL 100000000 // scale value for PixC (see formula in datasheet)
#define NROFTAELEMENTS 7    // number of columns (ambient temperature steps)
#define NROFADELEMENTS 471  // number of rows (digit steps)
#define TAEQUIDISTANCE 100   // distance between two columns
#define ADEQUIDISTANCE 64    // distance between two rows
#define ADEXPBITS 6
#define TABLEOFFSET 256 // table offset in digits


// SENSOR INFO
#define NUMBER_OF_PIXEL 64 // number of all pixels
#define NUMBER_OF_BLOCKS 1 // number of blocks for each half
#define PIXEL_PER_BLOCK 64 // number of pixels of each block
#define PIXEL_PER_COLUMN 8 // number of pixels of each column
#define PIXEL_PER_ROW 8 // number of pixels of each row
#define ROW_PER_BLOCK 8 // number of rows of each block
#define ALLOWED_DEADPIX 0 // max. 0.5% of the pixel number
#define ATC_ACTIVE 0 // 1 - sensor has... / 0 - sensor hasn't a cyclops
#define ATC_POS 0 // postion of the cyclops in block reading order
#define PTAT_POS 0 // position of PTAT in block reading order
#define VDD_POS 0 // postion of VDD in block reading order
#define PTAT_VDD_SWITCH 0 // 1 - PTAT and VDD alternate after each pic / 0 - not
#define BLOCK_LENGTH 130 // number of char in each block
#define DATA_POS 2  // position of first data byte in each block


// SENSOR REGISTER
#define TOP_HALF 0x0A // data of top half
#define BOTTOM_HALF 0x0B // data of bot half
#define CONFIGURATION_REGISTER 0x01 // configuration register (WRITE only)
// |  7  |  6  |  5  |  4  |   3   |    2     |   1   |    0   |
// |    RFU    |   Block   | Start | VDD_MEAS | BLIND | WAKEUP |
#define STATUS_REGISTER 0x02 // adress of status register (READ only)
// |  7  |  6  |  5  |  4  |   3   |    2     |   1   |    0   |
// |    RFU    |   Block   |  RFU  | VDD_MEAS | BLIND |   EOC  |
#define TRIM_REGISTER1 0x03 // adress for trim register 1 (WRITE only)
// |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
// |    RFU    |  REF_CAL  |         MBIT          |
#define TRIM_REGISTER2 0x04 // adress for trim register 2 (WRITE only)
// |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
// |       RFU       |       BIAS TRIM TOP         |
#define TRIM_REGISTER3 0x05 // adress for trim register 3 (WRITE only)
// |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
// |       RFU       |       BIAS TRIM BOT         |
#define TRIM_REGISTER4 0x06 // adress for trim register 4 (WRITE only)
// |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
// |       RFU |             CLK TRIM              |
#define TRIM_REGISTER5 0x07 // adress for trim register 5 (WRITE only)
// |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
// |       RFU       |        BPA TRIM TOP         |
#define TRIM_REGISTER6 0x08 // adress for trim register 6 (WRITE only)
// |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
// |       RFU       |       BPA TRIM BOT          |
#define TRIM_REGISTER7 0x09 // adress for trim register 7 (WRITE only)
// |  7  |  6  |  5  |  4  |  3  |  2  |  1  |  0  |
// |       PU SDA TRIM     |       PU SDA TRIM     |


// EEPROM COMMANDS
#define STANDBY 0x00
#define ACTIVE 0x01
#define NORMAL_ERASE 0x02
#define NORMAL_WRITE 0x03
#define BLOCK_ERASE 0x04
#define BLOCK_WRITE 0x05
#define NORMAL_READ 0x06
#define SET_ADDRESS 0x09
#define SET_DATA 0x0A
#define GET_DATA 0x0B

// EEPROM REGISTER
#define E_PIXCMIN_1 0x0000 // Min of PixC, stored as float in four 8-bit fields
#define E_PIXCMIN_2 0x0001
#define E_PIXCMAX_1 0x0002// Max of PixC, stored as float in four 8-bit fields
#define E_PIXCMAX_2 0x0003
#define E_GRADSCALE 0x0008 // stored as unsigned char, important for PTAT comp.
#define E_GLOBALGAIN 0x0009 // global gain, stored as unsigned short
#define E_TABLENUMBER 0x000C // table number of this sensor, stored as unsigned short
#define E_EPSILON 0x000D // emissivity in percentage, stored as unsigned char
#define E_MBIT_CALIB 0x001A // calibration settings of trim register 1
#define E_BIAS_CALIB 0x001B // calibration settings of trim register 2 & 3
#define E_CLK_CALIB 0x001C // calibration settings of trim register 4
#define E_BPA_CALIB 0x001D // calibration settings of trim register 5 & 6
#define E_PU_CALIB 0x001E // calibration settings of trim register 7
//#define E_ARRAYTYPE 0x0022 // array type of this sensor
#define E_PTATTH1 0x002C // HS calibration value
#define E_PTATTH2 0x002D // HS calibration value
#define E_PTATGR_1 0x0034 // PTAT gradient stored as float in two 16-bit fields
#define E_PTATGR_2 0x0035
#define E_PTATOFF_1 0x0036 // PTAT offset stored as float in two 16-bit fields
#define E_PTATOFF_2 0x0037
//#define E_GLOBALOFF 0x0054 // global offset, stored as signed char
#define E_MBIT_USER 0x0020 // user settings of trim register 1
#define E_BIAS_USER 0x0021 // user settings of trim register 2 & 3
#define E_CLK_USER 0x0022 // user settings of trim register 4
#define E_BPA_USER 0x0023 // user settings of trim register 5 & 6
#define E_PU_USER 0x0024 // user settings of trim register 7
#define E_ID1 0x003A // sensor idenification number, stored as unsigned long (1 of 4)
#define E_ID2 0x003B
#define E_THGRAD 0x040 // first register of thermal gradient
#define E_THOFFSET 0x0080 // first register of thermal offset 
#define E_PIJ 0x00C0 // first register of pixel constants (PixC)
#define EEPROM_SIZE 0x100

const unsigned char LUTshape[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 0, 0, 0, 1},
  {0, 1, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0, 1, 0, 1},
  {0, 1, 0, 1, 1, 1, 0, 1},
  {0, 1, 0, 0, 0, 0, 0, 1},
  {0, 1, 0, 1, 1, 1, 1, 1},
};

const unsigned int TempTable [NROFADELEMENTS][NROFTAELEMENTS]={
{  0x0000, 1533, 1945, 2222, 2445, 2637, 2811  },
{ 1866, 2125, 2336, 2519, 2685, 2838, 2983  },
{ 2290, 2452, 2602, 2743, 2877, 3007, 3132  },
{ 2568, 2690, 2809, 2926, 3040, 3153, 3263  },
{ 2782, 2882, 2982, 3082, 3182, 3282, 3382  },
{ 2959, 3044, 3131, 3219, 3308, 3399, 3490  },
{ 3111, 3185, 3263, 3342, 3423, 3506, 3590  },
{ 3245, 3312, 3381, 3454, 3528, 3604, 3683  },
{ 3365, 3426, 3490, 3556, 3625, 3696, 3770  },
{ 3475, 3531, 3589, 3651, 3715, 3782, 3851  },
{ 3575, 3627, 3682, 3740, 3800, 3863, 3928  },
{ 3669, 3718, 3769, 3823, 3880, 3940, 4002  },
{ 3757, 3802, 3851, 3902, 3956, 4012, 4071  },
{ 3839, 3882, 3928, 3976, 4028, 4082, 4138  },
{ 3917, 3958, 4001, 4047, 4096, 4148, 4202  },
{ 3991, 4030, 4071, 4115, 4162, 4211, 4263  },
{ 4061, 4098, 4138, 4180, 4225, 4272, 4322  },
{ 4128, 4164, 4201, 4242, 4285, 4331, 4379  },
{ 4192, 4226, 4263, 4302, 4343, 4387, 4434  },
{ 4254, 4287, 4322, 4359, 4399, 4442, 4487  },
{ 4313, 4345, 4379, 4415, 4454, 4495, 4541  },
{ 4371, 4401, 4434, 4469, 4506, 4547, 4595  },
{ 4426, 4455, 4487, 4520, 4556, 4600, 4650  },
{ 4479, 4474, 4536, 4568, 4608, 4654, 4707  },
{ 4530, 4554, 4583, 4619, 4661, 4709, 4761  },
{ 4573, 4599, 4632, 4670, 4715, 4763, 4812  },
{ 4617, 4647, 4682, 4723, 4768, 4814, 4862  },
{ 4663, 4696, 4734, 4775, 4818, 4863, 4910  },
{ 4711, 4746, 4785, 4825, 4867, 4912, 4958  },
{ 4762, 4797, 4835, 4874, 4916, 4959, 5005  },
{ 4812, 4847, 4884, 4923, 4963, 5006, 5051  },
{ 4862, 4896, 4932, 4970, 5010, 5052, 5096  },
{ 4910, 4944, 4979, 5017, 5056, 5097, 5140  },
{ 4958, 4991, 5026, 5062, 5101, 5141, 5184  },
{ 5005, 5037, 5071, 5107, 5145, 5185, 5226  },
{ 5051, 5083, 5116, 5152, 5189, 5228, 5269  },
{ 5096, 5127, 5160, 5195, 5232, 5270, 5310  },
{ 5140, 5171, 5203, 5238, 5274, 5312, 5351  },
{ 5184, 5214, 5246, 5280, 5315, 5353, 5392  },
{ 5227, 5256, 5288, 5321, 5356, 5393, 5431  },
{ 5269, 5298, 5329, 5362, 5396, 5433, 5470  },
{ 5310, 5339, 5370, 5402, 5436, 5472, 5509  },
{ 5351, 5380, 5410, 5442, 5475, 5510, 5547  },
{ 5392, 5420, 5449, 5481, 5514, 5548, 5585  },
{ 5431, 5459, 5488, 5519, 5552, 5586, 5622  },
{ 5471, 5498, 5527, 5557, 5589, 5623, 5658  },
{ 5509, 5536, 5565, 5595, 5626, 5660, 5695  },
{ 5547, 5574, 5602, 5632, 5663, 5696, 5730  },
{ 5585, 5611, 5639, 5668, 5699, 5731, 5766  },
{ 5622, 5648, 5675, 5704, 5735, 5767, 5800  },
{ 5659, 5684, 5711, 5740, 5770, 5802, 5835  },
{ 5695, 5720, 5747, 5775, 5805, 5836, 5869  },
{ 5731, 5755, 5782, 5810, 5839, 5870, 5903  },
{ 5766, 5790, 5816, 5844, 5873, 5904, 5936  },
{ 5801, 5825, 5851, 5878, 5907, 5937, 5969  },
{ 5835, 5859, 5885, 5911, 5940, 5970, 6001  },
{ 5869, 5893, 5918, 5945, 5973, 6003, 6034  },
{ 5903, 5926, 5951, 5978, 6005, 6035, 6066  },
{ 5936, 5959, 5984, 6010, 6038, 6067, 6097  },
{ 5969, 5992, 6016, 6042, 6069, 6098, 6128  },
{ 6002, 6024, 6048, 6074, 6101, 6129, 6159  },
{ 6034, 6056, 6080, 6105, 6132, 6160, 6190  },
{ 6066, 6088, 6112, 6137, 6163, 6191, 6220  },
{ 6097, 6119, 6143, 6167, 6194, 6221, 6250  },
{ 6129, 6150, 6173, 6198, 6224, 6251, 6280  },
{ 6160, 6181, 6204, 6228, 6254, 6281, 6310  },
{ 6190, 6212, 6234, 6258, 6284, 6311, 6339  },
{ 6220, 6242, 6264, 6288, 6313, 6340, 6368  },
{ 6251, 6271, 6294, 6317, 6342, 6369, 6397  },
{ 6280, 6301, 6323, 6347, 6371, 6397, 6425  },
{ 6310, 6330, 6352, 6375, 6400, 6426, 6453  },
{ 6339, 6359, 6381, 6404, 6428, 6454, 6481  },
{ 6368, 6388, 6410, 6432, 6457, 6482, 6509  },
{ 6397, 6417, 6438, 6461, 6485, 6510, 6536  },
{ 6425, 6445, 6466, 6489, 6512, 6537, 6564  },
{ 6453, 6473, 6494, 6516, 6540, 6565, 6591  },
{ 6481, 6501, 6522, 6544, 6567, 6592, 6618  },
{ 6509, 6528, 6549, 6571, 6594, 6618, 6644  },
{ 6537, 6556, 6576, 6598, 6621, 6645, 6671  },
{ 6564, 6583, 6603, 6625, 6647, 6671, 6697  },
{ 6591, 6610, 6630, 6651, 6674, 6698, 6723  },
{ 6618, 6636, 6656, 6678, 6700, 6724, 6749  },
{ 6644, 6663, 6683, 6704, 6726, 6749, 6774  },
{ 6671, 6689, 6709, 6730, 6752, 6775, 6800  },
{ 6697, 6715, 6735, 6755, 6777, 6801, 6825  },
{ 6723, 6741, 6760, 6781, 6803, 6826, 6850  },
{ 6749, 6767, 6786, 6806, 6828, 6851, 6875  },
{ 6774, 6792, 6811, 6832, 6853, 6876, 6900  },
{ 6800, 6818, 6837, 6857, 6878, 6900, 6924  },
{ 6825, 6843, 6861, 6881, 6903, 6925, 6949  },
{ 6850, 6868, 6886, 6906, 6927, 6949, 6973  },
{ 6875, 6892, 6911, 6931, 6951, 6973, 6997  },
{ 6900, 6917, 6935, 6955, 6976, 6998, 7021  },
{ 6924, 6941, 6960, 6979, 7000, 7021, 7044  },
{ 6949, 6966, 6984, 7003, 7023, 7045, 7068  },
{ 6973, 6990, 7008, 7027, 7047, 7069, 7091  },
{ 6997, 7014, 7032, 7051, 7071, 7092, 7115  },
{ 7021, 7037, 7055, 7074, 7094, 7115, 7138  },
{ 7044, 7061, 7079, 7097, 7117, 7138, 7161  },
{ 7068, 7084, 7102, 7121, 7140, 7161, 7183  },
{ 7091, 7108, 7125, 7144, 7163, 7184, 7206  },
{ 7115, 7131, 7148, 7167, 7186, 7207, 7229  },
{ 7138, 7154, 7171, 7189, 7209, 7229, 7251  },
{ 7161, 7177, 7194, 7212, 7231, 7252, 7273  },
{ 7183, 7199, 7216, 7235, 7254, 7274, 7295  },
{ 7206, 7222, 7239, 7257, 7276, 7296, 7317  },
{ 7229, 7244, 7261, 7279, 7298, 7318, 7339  },
{ 7251, 7267, 7283, 7301, 7320, 7340, 7361  },
{ 7273, 7289, 7305, 7323, 7342, 7362, 7383  },
{ 7295, 7311, 7327, 7345, 7364, 7383, 7404  },
{ 7317, 7333, 7349, 7367, 7385, 7405, 7425  },
{ 7339, 7355, 7371, 7388, 7407, 7426, 7447  },
{ 7361, 7376, 7392, 7410, 7428, 7447, 7468  },
{ 7383, 7398, 7414, 7431, 7449, 7468, 7489  },
{ 7404, 7419, 7435, 7452, 7470, 7489, 7510  },
{ 7426, 7440, 7456, 7473, 7491, 7510, 7530  },
{ 7447, 7462, 7477, 7494, 7512, 7531, 7551  },
{ 7468, 7483, 7498, 7515, 7533, 7552, 7572  },
{ 7489, 7504, 7519, 7536, 7554, 7572, 7592  },
{ 7510, 7524, 7540, 7557, 7574, 7593, 7612  },
{ 7531, 7545, 7561, 7577, 7595, 7613, 7633  },
{ 7551, 7566, 7581, 7597, 7615, 7633, 7653  },
{ 7572, 7586, 7601, 7618, 7635, 7653, 7673  },
{ 7592, 7607, 7622, 7638, 7655, 7673, 7693  },
{ 7613, 7627, 7642, 7658, 7675, 7693, 7713  },
{ 7633, 7647, 7662, 7678, 7695, 7713, 7732  },
{ 7653, 7667, 7682, 7698, 7715, 7733, 7752  },
{ 7673, 7687, 7702, 7718, 7735, 7753, 7771  },
{ 7693, 7707, 7722, 7737, 7754, 7772, 7791  },
{ 7713, 7727, 7741, 7757, 7774, 7791, 7810  },
{ 7732, 7746, 7761, 7777, 7793, 7811, 7829  },
{ 7752, 7766, 7780, 7796, 7812, 7830, 7849  },
{ 7772, 7785, 7800, 7815, 7832, 7849, 7868  },
{ 7791, 7805, 7819, 7834, 7851, 7868, 7887  },
{ 7810, 7824, 7838, 7854, 7870, 7887, 7905  },
{ 7830, 7843, 7857, 7873, 7889, 7906, 7924  },
{ 7849, 7862, 7876, 7892, 7908, 7925, 7943  },
{ 7868, 7881, 7895, 7910, 7926, 7944, 7962  },
{ 7887, 7900, 7914, 7929, 7945, 7962, 7980  },
{ 7906, 7919, 7933, 7948, 7964, 7981, 7999  },
{ 7924, 7937, 7951, 7966, 7982, 7999, 8017  },
{ 7943, 7956, 7970, 7985, 8001, 8017, 8035  },
{ 7962, 7975, 7989, 8003, 8019, 8036, 8053  },
{ 7980, 7993, 8007, 8022, 8037, 8054, 8071  },
{ 7999, 8011, 8025, 8040, 8056, 8072, 8089  },
{ 8017, 8030, 8044, 8058, 8074, 8090, 8107  },
{ 8035, 8048, 8062, 8076, 8092, 8108, 8125  },
{ 8053, 8066, 8080, 8094, 8110, 8126, 8143  },
{ 8072, 8084, 8098, 8112, 8127, 8144, 8161  },
{ 8090, 8102, 8116, 8130, 8145, 8161, 8178  },
{ 8108, 8120, 8133, 8148, 8163, 8179, 8196  },
{ 8125, 8138, 8151, 8165, 8181, 8197, 8214  },
{ 8143, 8156, 8169, 8183, 8198, 8214, 8231  },
{ 8161, 8173, 8187, 8201, 8216, 8232, 8248  },
{ 8179, 8191, 8204, 8218, 8233, 8249, 8266  },
{ 8196, 8208, 8222, 8236, 8250, 8266, 8283  },
{ 8214, 8226, 8239, 8253, 8268, 8283, 8300  },
{ 8231, 8243, 8256, 8270, 8285, 8301, 8317  },
{ 8248, 8261, 8274, 8287, 8302, 8318, 8334  },
{ 8266, 8278, 8291, 8304, 8319, 8335, 8351  },
{ 8283, 8295, 8308, 8322, 8336, 8352, 8368  },
{ 8300, 8312, 8325, 8339, 8353, 8368, 8385  },
{ 8317, 8329, 8342, 8355, 8370, 8385, 8401  },
{ 8334, 8346, 8359, 8372, 8387, 8402, 8418  },
{ 8351, 8363, 8376, 8389, 8403, 8419, 8435  },
{ 8368, 8380, 8392, 8406, 8420, 8435, 8451  },
{ 8385, 8396, 8409, 8422, 8437, 8452, 8468  },
{ 8401, 8413, 8426, 8439, 8453, 8468, 8484  },
{ 8418, 8430, 8442, 8456, 8470, 8485, 8500  },
{ 8435, 8446, 8459, 8472, 8486, 8501, 8517  },
{ 8451, 8463, 8475, 8488, 8502, 8517, 8533  },
{ 8468, 8479, 8492, 8505, 8519, 8533, 8549  },
{ 8484, 8496, 8508, 8521, 8535, 8550, 8565  },
{ 8500, 8512, 8524, 8537, 8551, 8566, 8581  },
{ 8517, 8528, 8540, 8553, 8567, 8582, 8597  },
{ 8533, 8544, 8557, 8569, 8583, 8598, 8613  },
{ 8549, 8561, 8573, 8585, 8599, 8614, 8629  },
{ 8565, 8577, 8589, 8601, 8615, 8630, 8645  },
{ 8581, 8593, 8605, 8617, 8631, 8645, 8661  },
{ 8597, 8609, 8620, 8633, 8647, 8661, 8676  },
{ 8613, 8624, 8636, 8649, 8663, 8677, 8692  },
{ 8629, 8640, 8652, 8665, 8678, 8692, 8708  },
{ 8645, 8656, 8668, 8680, 8694, 8708, 8723  },
{ 8661, 8672, 8684, 8696, 8709, 8724, 8739  },
{ 8676, 8687, 8699, 8712, 8725, 8739, 8754  },
{ 8692, 8703, 8715, 8727, 8740, 8755, 8769  },
{ 8708, 8719, 8730, 8743, 8756, 8770, 8785  },
{ 8723, 8734, 8746, 8758, 8771, 8785, 8800  },
{ 8739, 8750, 8761, 8773, 8787, 8800, 8815  },
{ 8754, 8765, 8776, 8789, 8802, 8816, 8830  },
{ 8769, 8780, 8792, 8804, 8817, 8831, 8845  },
{ 8785, 8796, 8807, 8819, 8832, 8846, 8861  },
{ 8800, 8811, 8822, 8834, 8847, 8861, 8876  },
{ 8815, 8826, 8837, 8849, 8862, 8876, 8891  },
{ 8830, 8841, 8852, 8865, 8877, 8891, 8905  },
{ 8846, 8856, 8867, 8880, 8892, 8906, 8920  },
{ 8861, 8871, 8882, 8894, 8907, 8921, 8935  },
{ 8876, 8886, 8897, 8909, 8922, 8936, 8950  },
{ 8891, 8901, 8912, 8924, 8937, 8950, 8965  },
{ 8906, 8916, 8927, 8939, 8952, 8965, 8979  },
{ 8920, 8931, 8942, 8954, 8966, 8980, 8994  },
{ 8935, 8946, 8957, 8968, 8981, 8994, 9008  },
{ 8950, 8960, 8971, 8983, 8996, 9009, 9023  },
{ 8965, 8975, 8986, 8998, 9010, 9023, 9038  },
{ 8979, 8990, 9001, 9012, 9025, 9038, 9052  },
{ 8994, 9004, 9015, 9027, 9039, 9052, 9066  },
{ 9009, 9019, 9030, 9041, 9054, 9067, 9081  },
{ 9023, 9033, 9044, 9056, 9068, 9081, 9095  },
{ 9038, 9048, 9059, 9070, 9082, 9095, 9109  },
{ 9052, 9062, 9073, 9084, 9097, 9110, 9123  },
{ 9066, 9076, 9087, 9099, 9111, 9124, 9138  },
{ 9081, 9091, 9102, 9113, 9125, 9138, 9152  },
{ 9095, 9105, 9116, 9127, 9139, 9152, 9166  },
{ 9109, 9119, 9130, 9141, 9153, 9166, 9180  },
{ 9124, 9134, 9144, 9156, 9168, 9180, 9194  },
{ 9138, 9148, 9158, 9170, 9182, 9194, 9208  },
{ 9152, 9162, 9172, 9184, 9196, 9208, 9222  },
{ 9166, 9176, 9186, 9198, 9210, 9222, 9236  },
{ 9180, 9190, 9200, 9212, 9223, 9236, 9250  },
{ 9194, 9204, 9214, 9225, 9237, 9250, 9263  },
{ 9208, 9218, 9228, 9239, 9251, 9264, 9277  },
{ 9222, 9232, 9242, 9253, 9265, 9278, 9291  },
{ 9236, 9245, 9256, 9267, 9279, 9291, 9304  },
{ 9250, 9259, 9270, 9281, 9292, 9305, 9318  },
{ 9263, 9273, 9283, 9294, 9306, 9319, 9332  },
{ 9277, 9287, 9297, 9308, 9320, 9332, 9345  },
{ 9291, 9300, 9311, 9322, 9333, 9346, 9359  },
{ 9305, 9314, 9324, 9335, 9347, 9359, 9372  },
{ 9318, 9328, 9338, 9349, 9360, 9373, 9386  },
{ 9332, 9341, 9351, 9362, 9374, 9386, 9399  },
{ 9345, 9355, 9365, 9376, 9387, 9400, 9412  },
{ 9359, 9368, 9378, 9389, 9401, 9413, 9426  },
{ 9372, 9382, 9392, 9403, 9414, 9426, 9439  },
{ 9386, 9395, 9405, 9416, 9427, 9440, 9452  },
{ 9399, 9409, 9419, 9429, 9441, 9453, 9466  },
{ 9413, 9422, 9432, 9443, 9454, 9466, 9479  },
{ 9426, 9435, 9445, 9456, 9467, 9479, 9492  },
{ 9439, 9449, 9458, 9469, 9480, 9492, 9505  },
{ 9452, 9462, 9472, 9482, 9494, 9505, 9518  },
{ 9466, 9475, 9485, 9495, 9507, 9519, 9531  },
{ 9479, 9488, 9498, 9509, 9520, 9532, 9544  },
{ 9492, 9501, 9511, 9522, 9533, 9545, 9557  },
{ 9505, 9514, 9524, 9535, 9546, 9558, 9570  },
{ 9518, 9527, 9537, 9548, 9559, 9571, 9583  },
{ 9531, 9540, 9550, 9561, 9572, 9583, 9596  },
{ 9544, 9553, 9563, 9573, 9585, 9596, 9609  },
{ 9557, 9566, 9576, 9586, 9597, 9609, 9622  },
{ 9570, 9579, 9589, 9599, 9610, 9622, 9634  },
{ 9583, 9592, 9602, 9612, 9623, 9635, 9647  },
{ 9596, 9605, 9615, 9625, 9636, 9647, 9660  },
{ 9609, 9618, 9627, 9638, 9649, 9660, 9672  },
{ 9622, 9631, 9640, 9650, 9661, 9673, 9685  },
{ 9634, 9643, 9653, 9663, 9674, 9685, 9698  },
{ 9647, 9656, 9666, 9676, 9687, 9698, 9710  },
{ 9660, 9669, 9678, 9688, 9699, 9711, 9723  },
{ 9672, 9681, 9691, 9701, 9712, 9723, 9735  },
{ 9685, 9694, 9703, 9713, 9724, 9736, 9748  },
{ 9698, 9707, 9716, 9726, 9737, 9748, 9760  },
{ 9710, 9719, 9728, 9739, 9749, 9761, 9773  },
{ 9723, 9732, 9741, 9751, 9762, 9773, 9785  },
{ 9735, 9744, 9753, 9763, 9774, 9785, 9797  },
{ 9748, 9757, 9766, 9776, 9786, 9798, 9810  },
{ 9760, 9769, 9778, 9788, 9799, 9810, 9822  },
{ 9773, 9781, 9791, 9801, 9811, 9822, 9834  },
{ 9785, 9794, 9803, 9813, 9823, 9835, 9846  },
{ 9797, 9806, 9815, 9825, 9836, 9847, 9859  },
{ 9810, 9818, 9828, 9837, 9848, 9859, 9871  },
{ 9822, 9831, 9840, 9850, 9860, 9871, 9883  },
{ 9834, 9843, 9852, 9862, 9872, 9883, 9895  },
{ 9846, 9855, 9864, 9874, 9884, 9895, 9907  },
{ 9859, 9867, 9876, 9886, 9896, 9908, 9919  },
{ 9871, 9879, 9889, 9898, 9909, 9920, 9931  },
{ 9883, 9892, 9901, 9910, 9921, 9932, 9943  },
{ 9895, 9904, 9913, 9922, 9933, 9944, 9955  },
{ 9907, 9916, 9925, 9934, 9945, 9956, 9967  },
{ 9919, 9928, 9937, 9946, 9957, 9967, 9979  },
{ 9931, 9940, 9949, 9958, 9969, 9979, 9991  },
{ 9943, 9952, 9961, 9970, 9980, 9991, 10003 },
{ 9955, 9964, 9973, 9982, 9992, 10003,  10015 },
{ 9967, 9976, 9984, 9994, 10004,  10015,  10026 },
{ 9979, 9987, 9996, 10006,  10016,  10027,  10038 },
{ 9991, 9999, 10008,  10018,  10028,  10039,  10050 },
{ 10003,  10011,  10020,  10030,  10040,  10050,  10062 },
{ 10015,  10023,  10032,  10041,  10051,  10062,  10073 },
{ 10026,  10035,  10044,  10053,  10063,  10074,  10085 },
{ 10038,  10046,  10055,  10065,  10075,  10085,  10097 },
{ 10050,  10058,  10067,  10076,  10086,  10097,  10108 },
{ 10062,  10070,  10079,  10088,  10098,  10109,  10120 },
{ 10073,  10082,  10090,  10100,  10110,  10120,  10131 },
{ 10085,  10093,  10102,  10111,  10121,  10132,  10143 },
{ 10097,  10105,  10114,  10123,  10133,  10143,  10154 },
{ 10108,  10116,  10125,  10134,  10144,  10155,  10166 },
{ 10120,  10128,  10137,  10146,  10156,  10166,  10177 },
{ 10131,  10140,  10148,  10157,  10167,  10178,  10189 },
{ 10143,  10151,  10160,  10169,  10179,  10189,  10200 },
{ 10154,  10163,  10171,  10180,  10190,  10201,  10212 },
{ 10166,  10174,  10183,  10192,  10202,  10212,  10223 },
{ 10177,  10185,  10194,  10203,  10213,  10223,  10234 },
{ 10189,  10197,  10205,  10215,  10224,  10235,  10246 },
{ 10200,  10208,  10217,  10226,  10236,  10246,  10257 },
{ 10212,  10220,  10228,  10237,  10247,  10257,  10268 },
{ 10223,  10231,  10240,  10249,  10258,  10269,  10279 },
{ 10234,  10242,  10251,  10260,  10270,  10280,  10291 },
{ 10246,  10254,  10262,  10271,  10281,  10291,  10302 },
{ 10257,  10265,  10273,  10282,  10292,  10302,  10313 },
{ 10268,  10276,  10285,  10294,  10303,  10313,  10324 },
{ 10279,  10287,  10296,  10305,  10314,  10324,  10335 },
{ 10291,  10299,  10307,  10316,  10325,  10336,  10346 },
{ 10302,  10310,  10318,  10327,  10337,  10347,  10357 },
{ 10313,  10321,  10329,  10338,  10348,  10358,  10368 },
{ 10324,  10332,  10340,  10349,  10359,  10369,  10379 },
{ 10335,  10343,  10351,  10360,  10370,  10380,  10390 },
{ 10346,  10354,  10362,  10371,  10381,  10391,  10401 },
{ 10357,  10365,  10373,  10382,  10392,  10402,  10412 },
{ 10368,  10376,  10384,  10393,  10403,  10413,  10423 },
{ 10379,  10387,  10395,  10404,  10414,  10424,  10434 },
{ 10390,  10398,  10406,  10415,  10425,  10435,  10445 },
{ 10401,  10409,  10417,  10426,  10436,  10445,  10456 },
{ 10412,  10420,  10428,  10437,  10446,  10456,  10467 },
{ 10423,  10431,  10439,  10448,  10457,  10467,  10478 },
{ 10434,  10442,  10450,  10459,  10468,  10478,  10488 },
{ 10445,  10453,  10461,  10470,  10479,  10489,  10499 },
{ 10456,  10464,  10472,  10480,  10490,  10500,  10510 },
{ 10467,  10474,  10483,  10491,  10500,  10510,  10521 },
{ 10478,  10485,  10493,  10502,  10511,  10521,  10531 },
{ 10488,  10496,  10504,  10513,  10522,  10532,  10542 },
{ 10499,  10507,  10515,  10523,  10533,  10542,  10553 },
{ 10510,  10518,  10526,  10534,  10543,  10553,  10563 },
{ 10521,  10528,  10536,  10545,  10554,  10564,  10574 },
{ 10531,  10539,  10547,  10556,  10565,  10574,  10585 },
{ 10542,  10550,  10558,  10566,  10575,  10585,  10595 },
{ 10553,  10560,  10568,  10577,  10586,  10596,  10606 },
{ 10563,  10571,  10579,  10587,  10596,  10606,  10616 },
{ 10574,  10582,  10589,  10598,  10607,  10617,  10627 },
{ 10585,  10592,  10600,  10609,  10618,  10627,  10637 },
{ 10595,  10603,  10611,  10619,  10628,  10638,  10648 },
{ 10606,  10613,  10621,  10630,  10639,  10648,  10658 },
{ 10616,  10624,  10632,  10640,  10649,  10659,  10669 },
{ 10627,  10634,  10642,  10651,  10660,  10669,  10679 },
{ 10637,  10645,  10653,  10661,  10670,  10679,  10690 },
{ 10648,  10655,  10663,  10671,  10680,  10690,  10700 },
{ 10658,  10666,  10673,  10682,  10691,  10700,  10710 },
{ 10669,  10676,  10684,  10692,  10701,  10711,  10721 },
{ 10679,  10686,  10694,  10703,  10712,  10721,  10731 },
{ 10690,  10697,  10705,  10713,  10722,  10731,  10741 },
{ 10700,  10707,  10715,  10723,  10732,  10742,  10752 },
{ 10710,  10718,  10725,  10734,  10742,  10752,  10762 },
{ 10721,  10728,  10736,  10744,  10753,  10762,  10772 },
{ 10731,  10738,  10746,  10754,  10763,  10772,  10782 },
{ 10741,  10749,  10756,  10764,  10773,  10783,  10792 },
{ 10752,  10759,  10766,  10775,  10783,  10793,  10803 },
{ 10762,  10769,  10777,  10785,  10794,  10803,  10813 },
{ 10772,  10779,  10787,  10795,  10804,  10813,  10823 },
{ 10782,  10789,  10797,  10805,  10814,  10823,  10833 },
{ 10792,  10800,  10807,  10815,  10824,  10833,  10843 },
{ 10803,  10810,  10817,  10826,  10834,  10844,  10853 },
{ 10813,  10820,  10828,  10836,  10844,  10854,  10863 },
{ 10823,  10830,  10838,  10846,  10854,  10864,  10873 },
{ 10833,  10840,  10848,  10856,  10865,  10874,  10883 },
{ 10843,  10850,  10858,  10866,  10875,  10884,  10893 },
{ 10853,  10860,  10868,  10876,  10885,  10894,  10903 },
{ 10863,  10870,  10878,  10886,  10895,  10904,  10913 },
{ 10873,  10881,  10888,  10896,  10905,  10914,  10923 },
{ 10884,  10891,  10898,  10906,  10915,  10924,  10933 },
{ 10894,  10901,  10908,  10916,  10925,  10934,  10943 },
{ 10904,  10911,  10918,  10926,  10935,  10944,  10953 },
{ 10914,  10921,  10928,  10936,  10944,  10954,  10963 },
{ 10923,  10930,  10938,  10946,  10954,  10963,  10973 },
{ 10933,  10940,  10948,  10956,  10964,  10973,  10983 },
{ 10943,  10950,  10958,  10966,  10974,  10983,  10993 },
{ 10953,  10960,  10968,  10976,  10984,  10993,  11003 },
{ 10963,  10970,  10978,  10985,  10994,  11003,  11012 },
{ 10973,  10980,  10987,  10995,  11004,  11013,  11022 },
{ 10983,  10990,  10997,  11005,  11013,  11022,  11032 },
{ 10993,  11000,  11007,  11015,  11023,  11032,  11042 },
{ 11003,  11009,  11017,  11025,  11033,  11042,  11051 },
{ 11012,  11019,  11027,  11034,  11043,  11052,  11061 },
{ 11022,  11029,  11036,  11044,  11053,  11061,  11071 },
{ 11032,  11039,  11046,  11054,  11062,  11071,  11080 },
{ 11042,  11049,  11056,  11064,  11072,  11081,  11090 },
{ 11051,  11058,  11066,  11073,  11082,  11090,  11100 },
{ 11061,  11068,  11075,  11083,  11091,  11100,  11109 },
{ 11071,  11078,  11085,  11093,  11101,  11110,  11119 },
{ 11081,  11087,  11095,  11102,  11111,  11119,  11129 },
{ 11090,  11097,  11104,  11112,  11120,  11129,  11138 },
{ 11100,  11107,  11114,  11122,  11130,  11139,  11148 },
{ 11110,  11116,  11123,  11131,  11139,  11148,  11157 },
{ 11119,  11126,  11133,  11141,  11149,  11158,  11167 },
{ 11129,  11135,  11143,  11150,  11159,  11167,  11176 },
{ 11138,  11145,  11152,  11160,  11168,  11177,  11186 },
{ 11148,  11155,  11162,  11169,  11178,  11186,  11195 },
{ 11157,  11164,  11171,  11179,  11187,  11196,  11205 },
{ 11167,  11174,  11181,  11188,  11197,  11205,  11214 },
{ 11177,  11183,  11190,  11198,  11206,  11215,  11224 },
{ 11186,  11193,  11200,  11207,  11216,  11224,  11233 },
{ 11196,  11202,  11209,  11217,  11225,  11234,  11243 },
{ 11205,  11212,  11219,  11226,  11234,  11243,  11252 },
{ 11214,  11221,  11228,  11236,  11244,  11252,  11261 },
{ 11224,  11231,  11238,  11245,  11253,  11262,  11271 },
{ 11233,  11240,  11247,  11255,  11263,  11271,  11280 },
{ 11243,  11249,  11256,  11264,  11272,  11281,  11290 },
{ 11252,  11259,  11266,  11273,  11281,  11290,  11299 },
{ 11262,  11268,  11275,  11283,  11291,  11299,  11308 },
{ 11271,  11277,  11285,  11292,  11300,  11308,  11317 },
{ 11280,  11287,  11294,  11301,  11309,  11318,  11327 },
{ 11290,  11296,  11303,  11311,  11319,  11327,  11336 },
{ 11299,  11305,  11312,  11320,  11328,  11336,  11345 },
{ 11308,  11315,  11322,  11329,  11337,  11346,  11354 },
{ 11318,  11324,  11331,  11338,  11346,  11355,  11364 },
{ 11327,  11333,  11340,  11348,  11356,  11364,  11373 },
{ 11336,  11343,  11350,  11357,  11365,  11373,  11382 },
{ 11345,  11352,  11359,  11366,  11374,  11382,  11391 },
{ 11355,  11361,  11368,  11375,  11383,  11392,  11400 },
{ 11364,  11370,  11377,  11385,  11392,  11401,  11410 },
{ 11373,  11379,  11386,  11394,  11402,  11410,  11419 },
{ 11382,  11389,  11395,  11403,  11411,  11419,  11428 },
{ 11391,  11398,  11405,  11412,  11420,  11428,  11437 },
{ 11400,  11407,  11414,  11421,  11429,  11437,  11446 },
{ 11410,  11416,  11423,  11430,  11438,  11446,  11455 },
{ 11419,  11425,  11432,  11439,  11447,  11455,  11464 },
{ 11428,  11434,  11441,  11448,  11456,  11464,  11473 },
{ 11437,  11443,  11450,  11457,  11465,  11473,  11482 },
{ 11446,  11452,  11459,  11467,  11474,  11483,  11491 },
{ 11455,  11461,  11468,  11476,  11483,  11492,  11500 },
{ 11464,  11471,  11477,  11485,  11492,  11501,  11509 },
{ 11473,  11480,  11486,  11494,  11501,  11510,  11518 },
{ 11482,  11489,  11495,  11503,  11510,  11518,  11527 },
{ 11491,  11498,  11504,  11512,  11519,  11527,  11536 },
{ 11500,  11507,  11513,  11521,  11528,  11536,  11545 },
{ 11509,  11516,  11522,  11530,  11537,  11545,  11554 },
{ 11518,  11525,  11531,  11538,  11546,  11554,  11563 },
{ 11527,  11534,  11540,  11547,  11555,  11563,  11572 },
{ 11536,  11542,  11549,  11556,  11564,  11572,  11581 },
{ 11545,  11551,  11558,  11565,  11573,  11581,  11590 },
{ 11554,  11560,  11567,  11574,  11582,  11590,  11598 },
{ 11563,  11569,  11576,  11583,  11591,  11599,  11607 },
{ 11572,  11578,  11585,  11592,  11599,  11607,  11616 },
{ 11581,  11587,  11594,  11601,  11608,  11616,  11625 },
{ 11590,  11596,  11602,  11610,  11617,  11625,  11634 },
{ 11598,  11605,  11611,  11618,  11626,  11634,  11642 },
{ 11607,  11613,  11620,  11627,  11635,  11643,  11651 },
{ 11616,  11622,  11629,  11636,  11644,  11652,  11660 },
{ 11625,  11631,  11638,  11645,  11652,  11660,  11669 },
{ 11634,  11640,  11646,  11654,  11661,  11669,  11677 },
{ 11642,  11649,  11655,  11662,  11670,  11678,  11686 },
{ 11651,  11657,  11664,  11671,  11679,  11686,  11695 },
{ 11660,  11666,  11673,  11680,  11687,  11695,  11704 },
{ 11669,  11675,  11681,  11688,  11696,  11704,  11712 },
{ 11678,  11684,  11690,  11697,  11705,  11713,  11721 },
{ 11686,  11692,  11699,  11706,  11713,  11721,  11730 },
{ 11695,  11701,  11708,  11715,  11722,  11730,  11738 },
{ 11704,  11710,  11716,  11723,  11731,  11739,  11747 },
{ 11712,  11718,  11725,  11732,  11739,  11747,  11756 },
{ 11721,  11727,  11734,  11741,  11748,  11756,  11764 },
{ 11730,  11736,  11742,  11749,  11757,  11764,  11773 },
{ 11738,  11744,  11751,  11758,  11765,  11773,  11781 },
{ 11747,  11753,  11759,  11766,  11774,  11782,  11790 },
{ 11756,  11762,  11768,  11775,  11782,  11790,  11798 },
{ 11764,  11770,  11777,  11784,  11791,  11799,  11807 },
{ 11773,  11779,  11785,  11792,  11799,  11807,  11816 },
{ 11781,  11787,  11794,  11801,  11808,  11816,  11824 },
{ 11790,  11796,  11802,  11809,  11817,  11824,  11833 },
{ 11798,  11804,  11811,  11818,  11825,  11833,  11841 },
{ 11807,  11813,  11819,  11826,  11834,  11841,  11850 },
{ 11816,  11822,  11828,  11835,  11842,  11850,  11858 },
{ 11824,  11830,  11836,  11843,  11851,  11858,  11866 },
{ 11833,  11839,  11845,  11852,  11859,  11867,  11875 },
{ 11841,  11847,  11853,  11860,  11868,  11875,  11883 },
{ 11850,  11856,  11862,  11869,  11876,  11884,  11892 },
{ 11858,  11864,  11870,  11877,  11884,  11892,  11900 },
{ 11867,  11872,  11879,  11886,  11893,  11900,  11909 }};


const unsigned int XTATemps[NROFTAELEMENTS]={2782,  2882, 2982, 3082, 3182, 3282, 3382};
const unsigned int YADValues[NROFADELEMENTS]={0,  64, 128,  192,  256,  320,  384,  448,  512,  576,  640,  704,  768,  832,  896,  960,  1024, 1088, 1152, 1216, 1280, 1344, 1408, 1472, 1536, 1600, 1664, 1728, 1792, 1856, 1920, 1984, 2048, 2112, 2176, 2240, 2304, 2368, 2432, 2496, 2560, 2624, 2688, 2752, 2816, 2880, 2944, 3008, 3072, 3136, 3200, 3264, 3328, 3392, 3456, 3520, 3584, 3648, 3712, 3776, 3840, 3904, 3968, 4032, 4096, 4160, 4224, 4288, 4352, 4416, 4480, 4544, 4608, 4672, 4736, 4800, 4864, 4928, 4992, 5056, 5120, 5184, 5248, 5312, 5376, 5440, 5504, 5568, 5632, 5696, 5760, 5824, 5888, 5952, 6016, 6080, 6144, 6208, 6272, 6336, 6400, 6464, 6528, 6592, 6656, 6720, 6784, 6848, 6912, 6976, 7040, 7104, 7168, 7232, 7296, 7360, 7424, 7488, 7552, 7616, 7680, 7744, 7808, 7872, 7936, 8000, 8064, 8128, 8192, 8256, 8320, 8384, 8448, 8512, 8576, 8640, 8704, 8768, 8832, 8896, 8960, 9024, 9088, 9152, 9216, 9280, 9344, 9408, 9472, 9536, 9600, 9664, 9728, 9792, 9856, 9920, 9984, 10048,  10112,  10176,  10240,  10304,  10368,  10432,  10496,  10560,  10624,  10688,  10752,  10816,  10880,  10944,  11008,  11072,  11136,  11200,  11264,  11328,  11392,  11456,  11520,  11584,  11648,  11712,  11776,  11840,  11904,  11968,  12032,  12096,  12160,  12224,  12288,  12352,  12416,  12480,  12544,  12608,  12672,  12736,  12800,  12864,  12928,  12992,  13056,  13120,  13184,  13248,  13312,  13376,  13440,  13504,  13568,  13632,  13696,  13760,  13824,  13888,  13952,  14016,  14080,  14144,  14208,  14272,  14336,  14400,  14464,  14528,  14592,  14656,  14720,  14784,  14848,  14912,  14976,  15040,  15104,  15168,  15232,  15296,  15360,  15424,  15488,  15552,  15616,  15680,  15744,  15808,  15872,  15936,  16000,  16064,  16128,  16192,  16256,  16320,  16384,  16448,  16512,  16576,  16640,  16704,  16768,  16832,  16896,  16960,  17024,  17088,  17152,  17216,  17280,  17344,  17408,  17472,  17536,  17600,  17664,  17728,  17792,  17856,  17920,  17984,  18048,  18112,  18176,  18240,  18304,  18368,  18432,  18496,  18560,  18624,  18688,  18752,  18816,  18880,  18944,  19008,  19072,  19136,  19200,  19264,  19328,  19392,  19456,  19520,  19584,  19648,  19712,  19776,  19840,  19904,  19968,  20032,  20096,  20160,  20224,  20288,  20352,  20416,  20480,  20544,  20608,  20672,  20736,  20800,  20864,  20928,  20992,  21056,  21120,  21184,  21248,  21312,  21376,  21440,  21504,  21568,  21632,  21696,  21760,  21824,  21888,  21952,  22016,  22080,  22144,  22208,  22272,  22336,  22400,  22464,  22528,  22592,  22656,  22720,  22784,  22848,  22912,  22976,  23040,  23104,  23168,  23232,  23296,  23360,  23424,  23488,  23552,  23616,  23680,  23744,  23808,  23872,  23936,  24000,  24064,  24128,  24192,  24256,  24320,  24384,  24448,  24512,  24576,  24640,  24704,  24768,  24832,  24896,  24960,  25024,  25088,  25152,  25216,  25280,  25344,  25408,  25472,  25536,  25600,  25664,  25728,  25792,  25856,  25920,  25984,  26048,  26112,  26176,  26240,  26304,  26368,  26432,  26496,  26560,  26624,  26688,  26752,  26816,  26880,  26944,  27008,  27072,  27136,  27200,  27264,  27328,  27392,  27456,  27520,  27584,  27648,  27712,  27776,  27840,  27904,  27968,  28032,  28096,  28160,  28224,  28288,  28352,  28416,  28480,  28544,  28608,  28672,  28736,  28800,  28864,  28928,  28992,  29056,  29120,  29184,  29248,  29312,  29376,  29440,  29504,  29568,  29632,  29696,  29760,  29824,  29888,  29952,  30016,  30080};

#endif // for #ifndef  _def_H
