#ifndef _def_H
#define _def_H

// DEVICE ADRESS
#define  SENSOR_ADDRESS          0x1A
#define  EEPROM_ADDRESS          0x50

// I2C CLOCK
#define CLOCK_SENSOR            1000000 
#define CLOCK_EEPROM            400000


// SETTING
#define PTAT_BUFFER_SIZE 10
#define VDD_BUFFER_SIZE 10
#define ELOFFSETS_BUFFER_SIZE 10
#define ELOFFSETS_FILTER_START_DELAY  100
#define START_WITH_BLOCK 4
#define READ_ELOFFSET_EVERYX 10


// WIFI SETTING
#define UDP_PACKET_LENGTH 1292
#define LAST_UDP_PACKET_LENGTH 1288
#define ACCESSPOINTNAME "HTPAd32x32L1k8"
#define ACCESSPOINTKEY "heimannsensor"

// PARAMETER LOOKUPTABLE
#define TABLENUMBER 115      // table number of this sensor type
#define PCSCALEVAL 100000000 // scale value for PixC (see formula in datasheet)
#define NROFTAELEMENTS 7    // number of columns (ambient temperature steps)
#define NROFADELEMENTS 471  // number of rows (digit steps)
#define TAEQUIDISTANCE 100   // distance between two columns
#define ADEQUIDISTANCE 64    // distance between two rows
#define ADEXPBITS 6
#define TABLEOFFSET 512 // table offset in digits


// SENSOR INFO
#define NUMBER_OF_PIXEL 1024 // number of all pixels
#define NUMBER_OF_BLOCKS 4 // number of blocks for each half
#define PIXEL_PER_BLOCK 128 // number of pixels of each block
#define PIXEL_PER_COLUMN 32 // number of pixels of each column
#define PIXEL_PER_ROW 32 // number of pixels of each row
#define ROW_PER_BLOCK 4 // number of rows of each block
#define ALLOWED_DEADPIX 5 // max. 0.5% of the pixel number
#define ATC_ACTIVE 0 // 1 - sensor has... / 0 - sensor hasn't a cyclops
#define ATC_POS 0 // postion of the cyclops in block reading order
#define PTAT_POS 0 // position of PTAT in block reading order
#define VDD_POS 0 // postion of VDD in block reading order
#define PTAT_VDD_SWITCH 1 // 1 - PTAT and VDD alternate after each pic / 0 - not
#define BLOCK_LENGTH 258 // number of char in each block
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


// EEPROM REGISTER
#define E_PIXCMIN_1 0x0000 // Min of PixC, stored as float in four 8-bit fields
#define E_PIXCMIN_2 0x0001
#define E_PIXCMIN_3 0x0002
#define E_PIXCMIN_4 0x0003
#define E_PIXCMAX_1 0x0004// Max of PixC, stored as float in four 8-bit fields
#define E_PIXCMAX_2 0x0005
#define E_PIXCMAX_3 0x0006
#define E_PIXCMAX_4 0x0007
#define E_GRADSCALE 0x0008 // stored as unsigned char, important for PTAT comp.
#define E_TABLENUMBER1 0x000B // table number of this sensor, stored as unsigned short
#define E_TABLENUMBER2 0x000C
#define E_EPSILON 0x000D // emissivity in percentage, stored as unsigned char
#define E_MBIT_CALIB 0x001A // calibration settings of trim register 1
#define E_BIAS_CALIB 0x001B // calibration settings of trim register 2 & 3
#define E_CLK_CALIB 0x001C // calibration settings of trim register 4
#define E_BPA_CALIB 0x001D // calibration settings of trim register 5 & 6
#define E_PU_CALIB 0x001E // calibration settings of trim register 7
#define E_ARRAYTYPE 0x0022 // array type of this sensor
#define E_VDDTH1_1 0x0026 // HS calibration value
#define E_VDDTH1_2 0x0027 // HS calibration value
#define E_VDDTH2_1 0x0028 // HS calibration value
#define E_VDDTH2_2 0x0029 // HS calibration value
#define E_PTATGR_1 0x0034 // PTAT gradient stored as float in four 8-bit fields
#define E_PTATGR_2 0x0035
#define E_PTATGR_3 0x0036
#define E_PTATGR_4 0x0037
#define E_PTATOFF_1 0x0038 // PTAT offset stored as float in four 8-bit fields
#define E_PTATOFF_2 0x0039
#define E_PTATOFF_3 0x003A
#define E_PTATOFF_4 0x003B
#define E_PTATTH1_1 0x003C // HS calibration value
#define E_PTATTH1_2 0x003D // HS calibration value
#define E_PTATTH2_1 0x003E // HS calibration value
#define E_PTATTH2_2 0x003F // HS calibration value
#define E_VDDSCGRAD 0x004E // HS calibration value
#define E_VDDSCOFF 0x004F // HS calibration value
#define E_GLOBALOFF 0x0054 // global offset, stored as signed char
#define E_GLOBALGAIN_1 0x0055 // global gain, stored as unsigned short
#define E_GLOBALGAIN_2 0x0056
#define E_MBIT_USER 0x0060 // user settings of trim register 1
#define E_BIAS_USER 0x0061 // user settings of trim register 2 & 3
#define E_CLK_USER 0x0062 // user settings of trim register 4
#define E_BPA_USER 0x0063 // user settings of trim register 5 & 6
#define E_PU_USER 0x0064 // user settings of trim register 7
#define E_ID1 0x0074 // sensor idenification number, stored as unsigned long (1 of 4)
#define E_ID2 0x0075
#define E_ID3 0x0076
#define E_ID4 0x0077
#define E_NROFDEFPIX 0x007F // number of defekt pixel, stored as unsigned char
#define E_DEADPIXADR 0x0080 // first register of dead adress
#define E_DEADPIXMASK 0x00B0 // first register of dead pixel mask
#define E_VDDCOMPGRAD 0x0340 // first register of VDD comp gradient
#define E_VDDCOMPOFF 0x0540 // first register ofVDD comp offset
#define E_THGRAD 0x0740 // first register of thermal gradient
#define E_THOFFSET 0x0F40 // first register of thermal offset 
#define E_PIJ 0x1740 // first register of pixel constants (PixC)
#define EEPROM_SIZE 0x1F3F // total number of EEPROM bytes

const unsigned char LUTshape[8][8] = {
  {0,0,0,0,0,0,0,0},
  {1,1,1,1,0,0,0,1},
  {0,1,0,0,0,0,0,1},
  {0,1,0,1,0,1,0,1},
  {0,1,0,1,0,1,0,1},
  {0,1,0,1,1,1,0,1},
  {0,1,0,0,0,0,0,1},
  {0,1,0,1,1,1,1,1},
};


const unsigned int TempTable [NROFADELEMENTS][NROFTAELEMENTS]={
{  2262, 2423, 2573, 2715, 2850, 2980, 3106  },
{ 2344, 2493, 2634, 2768, 2897, 3022, 3144  },
{ 2420, 2558, 2691, 2818, 2942, 3063, 3180  },
{ 2490, 2620, 2745, 2867, 2985, 3102, 3216  },
{ 2555, 2678, 2797, 2913, 3027, 3140, 3251  },
{ 2617, 2732, 2846, 2958, 3068, 3177, 3285  },
{ 2675, 2785, 2893, 3001, 3107, 3213, 3318  },
{ 2730, 2834, 2938, 3042, 3145, 3248, 3351  },
{ 2782, 2882, 2982, 3082, 3182, 3282, 3382  },
{ 2832, 2928, 3024, 3121, 3218, 3315, 3413  },
{ 2880, 2972, 3065, 3158, 3253, 3348, 3443  },
{ 2926, 3014, 3104, 3195, 3287, 3379, 3472  },
{ 2970, 3055, 3142, 3230, 3320, 3410, 3501  },
{ 3012, 3095, 3179, 3265, 3352, 3440, 3529  },
{ 3053, 3133, 3215, 3298, 3383, 3470, 3557  },
{ 3093, 3170, 3250, 3331, 3414, 3498, 3584  },
{ 3131, 3207, 3284, 3363, 3444, 3527, 3611  },
{ 3169, 3242, 3317, 3394, 3474, 3554, 3637  },
{ 3205, 3276, 3349, 3425, 3502, 3582, 3663  },
{ 3240, 3309, 3381, 3455, 3531, 3608, 3688  },
{ 3274, 3342, 3412, 3484, 3558, 3634, 3713  },
{ 3308, 3373, 3442, 3512, 3585, 3660, 3737  },
{ 3340, 3404, 3471, 3540, 3612, 3685, 3761  },
{ 3372, 3435, 3500, 3568, 3638, 3710, 3785  },
{ 3403, 3464, 3528, 3595, 3664, 3735, 3808  },
{ 3433, 3493, 3556, 3621, 3689, 3759, 3831  },
{ 3463, 3522, 3583, 3647, 3714, 3782, 3853  },
{ 3492, 3549, 3610, 3673, 3738, 3806, 3875  },
{ 3520, 3577, 3636, 3698, 3762, 3828, 3897  },
{ 3548, 3603, 3662, 3722, 3785, 3851, 3919  },
{ 3575, 3630, 3687, 3746, 3809, 3873, 3940  },
{ 3602, 3655, 3712, 3770, 3832, 3895, 3961  },
{ 3628, 3681, 3736, 3794, 3854, 3917, 3982  },
{ 3654, 3706, 3760, 3817, 3876, 3938, 4002  },
{ 3680, 3730, 3784, 3840, 3898, 3959, 4022  },
{ 3705, 3754, 3807, 3862, 3920, 3980, 4042  },
{ 3729, 3778, 3830, 3884, 3941, 4000, 4063  },
{ 3753, 3801, 3852, 3906, 3962, 4021, 4082  },
{ 3777, 3824, 3874, 3927, 3983, 4041, 4100  },
{ 3800, 3847, 3896, 3948, 4003, 4062, 4119  },
{ 3823, 3869, 3918, 3969, 4023, 4080, 4137  },
{ 3846, 3891, 3939, 3990, 4043, 4099, 4155  },
{ 3868, 3913, 3960, 4010, 4065, 4117, 4173  },
{ 3890, 3934, 3981, 4030, 4083, 4135, 4191  },
{ 3912, 3955, 4001, 4054, 4102, 4153, 4208  },
{ 3933, 3976, 4022, 4072, 4120, 4171, 4225  },
{ 3954, 3997, 4042, 4091, 4138, 4188, 4243  },
{ 3975, 4017, 4066, 4044, 4155, 4206, 4260  },
{ 3996, 4037, 4084, 4126, 4173, 4223, 4277  },
{ 4016, 4063, 4102, 4144, 4190, 4240, 4293  },
{ 4036, 4081, 4043, 4162, 4207, 4257, 4310  },
{ 4064, 4099, 4137, 4179, 4225, 4274, 4326  },
{ 4082, 4027, 4154, 4196, 4241, 4290, 4343  },
{ 4099, 4047, 4171, 4213, 4258, 4307, 4359  },
{ 4014, 4151, 4188, 4230, 4275, 4323, 4375  },
{ 4034, 4168, 4205, 4247, 4291, 4340, 4391  },
{ 4151, 4185, 4222, 4263, 4308, 4356, 4407  },
{ 4167, 4201, 4239, 4280, 4324, 4372, 4423  },
{ 4184, 4218, 4255, 4296, 4340, 4388, 4439  },
{ 4201, 4234, 4271, 4312, 4356, 4404, 4454  },
{ 4217, 4251, 4288, 4328, 4372, 4419, 4470  },
{ 4233, 4267, 4304, 4344, 4388, 4435, 4485  },
{ 4249, 4283, 4320, 4360, 4403, 4450, 4501  },
{ 4265, 4299, 4335, 4376, 4419, 4466, 4516  },
{ 4281, 4315, 4351, 4391, 4434, 4481, 4531  },
{ 4297, 4330, 4367, 4407, 4450, 4496, 4546  },
{ 4313, 4346, 4382, 4422, 4465, 4512, 4561  },
{ 4328, 4361, 4398, 4437, 4480, 4527, 4576  },
{ 4344, 4377, 4413, 4453, 4496, 4542, 4591  },
{ 4359, 4392, 4428, 4468, 4511, 4557, 4606  },
{ 4374, 4407, 4443, 4483, 4526, 4572, 4621  },
{ 4389, 4422, 4458, 4498, 4541, 4586, 4635  },
{ 4404, 4437, 4473, 4513, 4555, 4601, 4650  },
{ 4419, 4452, 4488, 4528, 4570, 4616, 4665  },
{ 4434, 4467, 4503, 4542, 4585, 4630, 4679  },
{ 4449, 4482, 4518, 4557, 4599, 4645, 4693  },
{ 4464, 4497, 4533, 4572, 4614, 4659, 4708  },
{ 4478, 4511, 4547, 4586, 4629, 4674, 4722  },
{ 4493, 4526, 4562, 4601, 4643, 4688, 4736  },
{ 4507, 4540, 4576, 4615, 4657, 4702, 4751  },
{ 4522, 4555, 4591, 4630, 4672, 4717, 4765  },
{ 4536, 4569, 4605, 4644, 4686, 4731, 4779  },
{ 4551, 4584, 4619, 4658, 4700, 4745, 4793  },
{ 4565, 4598, 4634, 4672, 4714, 4759, 4807  },
{ 4579, 4612, 4648, 4687, 4728, 4773, 4821  },
{ 4593, 4626, 4662, 4701, 4742, 4787, 4835  },
{ 4607, 4640, 4676, 4715, 4756, 4801, 4849  },
{ 4621, 4654, 4690, 4729, 4770, 4815, 4863  },
{ 4635, 4668, 4704, 4743, 4784, 4829, 4877  },
{ 4649, 4682, 4718, 4757, 4798, 4843, 4890  },
{ 4663, 4696, 4732, 4771, 4812, 4857, 4904  },
{ 4677, 4710, 4746, 4784, 4826, 4870, 4918  },
{ 4691, 4724, 4759, 4798, 4840, 4884, 4931  },
{ 4704, 4737, 4773, 4812, 4853, 4898, 4945  },
{ 4718, 4751, 4787, 4826, 4867, 4911, 4959  },
{ 4732, 4765, 4801, 4839, 4881, 4925, 4972  },
{ 4745, 4778, 4814, 4853, 4894, 4939, 4986  },
{ 4759, 4792, 4828, 4866, 4908, 4952, 4999  },
{ 4773, 4806, 4841, 4880, 4921, 4966, 5013  },
{ 4786, 4819, 4855, 4893, 4935, 4979, 5026  },
{ 4800, 4833, 4868, 4907, 4948, 4993, 5040  },
{ 4813, 4846, 4882, 4920, 4962, 5006, 5053  },
{ 4826, 4859, 4895, 4934, 4975, 5019, 5066  },
{ 4840, 4873, 4909, 4947, 4989, 5033, 5080  },
{ 4853, 4886, 4922, 4961, 5002, 5046, 5093  },
{ 4866, 4900, 4935, 4974, 5015, 5059, 5106  },
{ 4880, 4913, 4949, 4987, 5029, 5073, 5119  },
{ 4893, 4926, 4962, 5000, 5042, 5086, 5133  },
{ 4906, 4939, 4975, 5014, 5055, 5099, 5146  },
{ 4919, 4952, 4988, 5027, 5068, 5112, 5159  },
{ 4932, 4966, 5002, 5040, 5081, 5125, 5172  },
{ 4945, 4979, 5015, 5053, 5095, 5139, 5185  },
{ 4959, 4992, 5028, 5066, 5108, 5152, 5198  },
{ 4972, 5005, 5041, 5080, 5121, 5165, 5211  },
{ 4985, 5018, 5054, 5093, 5134, 5178, 5224  },
{ 4998, 5031, 5067, 5106, 5147, 5191, 5237  },
{ 5011, 5044, 5080, 5119, 5160, 5204, 5249  },
{ 5024, 5057, 5093, 5132, 5173, 5217, 5261  },
{ 5037, 5070, 5106, 5145, 5186, 5229, 5273  },
{ 5050, 5083, 5119, 5158, 5199, 5242, 5285  },
{ 5062, 5096, 5132, 5171, 5212, 5254, 5297  },
{ 5075, 5109, 5145, 5184, 5225, 5266, 5309  },
{ 5088, 5122, 5158, 5197, 5237, 5278, 5321  },
{ 5101, 5135, 5171, 5209, 5249, 5290, 5333  },
{ 5114, 5148, 5184, 5222, 5262, 5303, 5345  },
{ 5127, 5160, 5197, 5235, 5274, 5315, 5357  },
{ 5140, 5173, 5209, 5247, 5286, 5326, 5369  },
{ 5152, 5186, 5222, 5259, 5298, 5338, 5381  },
{ 5165, 5199, 5234, 5271, 5310, 5350, 5392  },
{ 5178, 5212, 5247, 5283, 5322, 5362, 5404  },
{ 5191, 5224, 5259, 5296, 5334, 5374, 5415  },
{ 5203, 5237, 5271, 5308, 5346, 5386, 5427  },
{ 5216, 5249, 5283, 5320, 5358, 5397, 5439  },
{ 5228, 5261, 5295, 5332, 5369, 5409, 5450  },
{ 5241, 5273, 5307, 5343, 5381, 5420, 5461  },
{ 5253, 5285, 5319, 5355, 5393, 5432, 5473  },
{ 5265, 5297, 5331, 5367, 5404, 5443, 5484  },
{ 5277, 5309, 5343, 5379, 5416, 5455, 5495  },
{ 5289, 5321, 5355, 5390, 5428, 5466, 5507  },
{ 5301, 5333, 5367, 5402, 5439, 5478, 5518  },
{ 5313, 5345, 5379, 5414, 5450, 5489, 5529  },
{ 5325, 5357, 5390, 5425, 5462, 5500, 5540  },
{ 5337, 5369, 5402, 5437, 5473, 5511, 5551  },
{ 5349, 5381, 5414, 5448, 5485, 5523, 5562  },
{ 5361, 5392, 5425, 5460, 5496, 5534, 5573  },
{ 5373, 5404, 5437, 5471, 5507, 5545, 5584  },
{ 5385, 5415, 5448, 5482, 5518, 5556, 5595  },
{ 5396, 5427, 5460, 5494, 5530, 5567, 5606  },
{ 5408, 5439, 5471, 5505, 5541, 5578, 5617  },
{ 5419, 5450, 5482, 5516, 5552, 5589, 5628  },
{ 5431, 5461, 5494, 5527, 5563, 5600, 5639  },
{ 5442, 5473, 5505, 5538, 5574, 5611, 5649  },
{ 5454, 5484, 5516, 5550, 5585, 5622, 5660  },
{ 5465, 5495, 5527, 5561, 5596, 5632, 5671  },
{ 5477, 5507, 5538, 5572, 5607, 5643, 5681  },
{ 5488, 5518, 5549, 5583, 5617, 5654, 5692  },
{ 5499, 5529, 5561, 5594, 5628, 5665, 5702  },
{ 5510, 5540, 5572, 5604, 5639, 5675, 5713  },
{ 5522, 5551, 5582, 5615, 5650, 5686, 5723  },
{ 5533, 5562, 5593, 5626, 5660, 5696, 5734  },
{ 5544, 5573, 5604, 5637, 5671, 5707, 5744  },
{ 5555, 5584, 5615, 5648, 5682, 5717, 5755  },
{ 5566, 5595, 5626, 5658, 5692, 5728, 5765  },
{ 5577, 5606, 5637, 5669, 5703, 5738, 5775  },
{ 5588, 5617, 5648, 5680, 5713, 5749, 5786  },
{ 5599, 5628, 5658, 5690, 5724, 5759, 5796  },
{ 5610, 5639, 5669, 5701, 5734, 5769, 5806  },
{ 5621, 5649, 5680, 5711, 5745, 5780, 5816  },
{ 5631, 5660, 5690, 5722, 5755, 5790, 5826  },
{ 5642, 5671, 5701, 5732, 5765, 5800, 5837  },
{ 5653, 5681, 5711, 5743, 5776, 5810, 5847  },
{ 5664, 5692, 5722, 5753, 5786, 5821, 5857  },
{ 5674, 5702, 5732, 5763, 5796, 5831, 5867  },
{ 5685, 5713, 5743, 5774, 5807, 5841, 5877  },
{ 5695, 5723, 5753, 5784, 5817, 5851, 5887  },
{ 5706, 5734, 5763, 5794, 5827, 5861, 5897  },
{ 5717, 5744, 5774, 5805, 5837, 5871, 5907  },
{ 5727, 5755, 5784, 5815, 5847, 5881, 5916  },
{ 5737, 5765, 5794, 5825, 5857, 5891, 5926  },
{ 5748, 5775, 5804, 5835, 5867, 5901, 5936  },
{ 5758, 5786, 5815, 5845, 5877, 5911, 5946  },
{ 5769, 5796, 5825, 5855, 5887, 5921, 5956  },
{ 5779, 5806, 5835, 5865, 5897, 5930, 5965  },
{ 5789, 5816, 5845, 5875, 5907, 5940, 5975  },
{ 5799, 5826, 5855, 5885, 5917, 5950, 5985  },
{ 5810, 5837, 5865, 5895, 5927, 5960, 5994  },
{ 5820, 5847, 5875, 5905, 5936, 5969, 6004  },
{ 5830, 5857, 5885, 5915, 5946, 5979, 6014  },
{ 5840, 5867, 5895, 5925, 5956, 5989, 6023  },
{ 5850, 5877, 5905, 5935, 5966, 5998, 6033  },
{ 5860, 5887, 5915, 5944, 5975, 6008, 6042  },
{ 5870, 5897, 5925, 5954, 5985, 6018, 6052  },
{ 5880, 5907, 5934, 5964, 5995, 6027, 6061  },
{ 5890, 5916, 5944, 5974, 6004, 6037, 6070  },
{ 5900, 5926, 5954, 5983, 6014, 6046, 6080  },
{ 5910, 5936, 5964, 5993, 6023, 6056, 6089  },
{ 5920, 5946, 5973, 6002, 6033, 6065, 6099  },
{ 5930, 5956, 5983, 6012, 6043, 6074, 6108  },
{ 5939, 5965, 5993, 6022, 6052, 6084, 6117  },
{ 5949, 5975, 6002, 6031, 6061, 6093, 6126  },
{ 5959, 5985, 6012, 6041, 6071, 6103, 6136  },
{ 5969, 5994, 6022, 6050, 6080, 6112, 6145  },
{ 5978, 6004, 6031, 6060, 6090, 6121, 6154  },
{ 5988, 6014, 6041, 6069, 6099, 6130, 6163  },
{ 5998, 6023, 6050, 6078, 6108, 6140, 6172  },
{ 6007, 6033, 6059, 6088, 6118, 6149, 6181  },
{ 6017, 6042, 6069, 6097, 6127, 6158, 6191  },
{ 6026, 6052, 6078, 6106, 6136, 6167, 6200  },
{ 6036, 6061, 6088, 6116, 6145, 6176, 6209  },
{ 6045, 6070, 6097, 6125, 6154, 6185, 6218  },
{ 6055, 6080, 6106, 6134, 6164, 6194, 6227  },
{ 6064, 6089, 6116, 6143, 6173, 6203, 6236  },
{ 6074, 6099, 6125, 6153, 6182, 6213, 6245  },
{ 6083, 6108, 6134, 6162, 6191, 6222, 6254  },
{ 6092, 6117, 6143, 6171, 6200, 6231, 6262  },
{ 6102, 6126, 6153, 6180, 6209, 6239, 6271  },
{ 6111, 6136, 6162, 6189, 6218, 6248, 6280  },
{ 6120, 6145, 6171, 6198, 6227, 6257, 6289  },
{ 6130, 6154, 6180, 6207, 6236, 6266, 6298  },
{ 6139, 6163, 6189, 6216, 6245, 6275, 6307  },
{ 6148, 6172, 6198, 6225, 6254, 6284, 6315  },
{ 6157, 6181, 6207, 6234, 6263, 6293, 6324  },
{ 6166, 6191, 6216, 6243, 6272, 6302, 6333  },
{ 6175, 6200, 6225, 6252, 6281, 6310, 6342  },
{ 6185, 6209, 6234, 6261, 6289, 6319, 6350  },
{ 6194, 6218, 6243, 6270, 6298, 6328, 6359  },
{ 6203, 6227, 6252, 6279, 6307, 6337, 6368  },
{ 6212, 6236, 6261, 6288, 6316, 6345, 6376  },
{ 6221, 6245, 6270, 6296, 6324, 6354, 6385  },
{ 6230, 6254, 6279, 6305, 6333, 6363, 6393  },
{ 6239, 6262, 6288, 6314, 6342, 6371, 6402  },
{ 6248, 6271, 6296, 6323, 6351, 6380, 6410  },
{ 6257, 6280, 6305, 6332, 6359, 6388, 6419  },
{ 6265, 6289, 6314, 6340, 6368, 6397, 6427  },
{ 6274, 6298, 6323, 6349, 6377, 6405, 6436  },
{ 6283, 6307, 6331, 6358, 6385, 6414, 6444  },
{ 6292, 6315, 6340, 6366, 6394, 6423, 6453  },
{ 6301, 6324, 6349, 6375, 6402, 6431, 6461  },
{ 6310, 6333, 6357, 6383, 6411, 6439, 6470  },
{ 6318, 6342, 6366, 6392, 6419, 6448, 6478  },
{ 6327, 6350, 6375, 6401, 6428, 6456, 6486  },
{ 6336, 6359, 6383, 6409, 6436, 6465, 6495  },
{ 6344, 6368, 6392, 6418, 6445, 6473, 6503  },
{ 6353, 6376, 6400, 6426, 6453, 6481, 6511  },
{ 6362, 6385, 6409, 6435, 6462, 6490, 6519  },
{ 6370, 6393, 6417, 6443, 6470, 6498, 6528  },
{ 6379, 6402, 6426, 6451, 6478, 6506, 6536  },
{ 6388, 6410, 6434, 6460, 6487, 6515, 6544  },
{ 6396, 6419, 6443, 6468, 6495, 6523, 6552  },
{ 6405, 6427, 6451, 6477, 6503, 6531, 6561  },
{ 6413, 6436, 6460, 6485, 6512, 6539, 6569  },
{ 6422, 6444, 6468, 6493, 6520, 6548, 6577  },
{ 6430, 6453, 6477, 6502, 6528, 6556, 6585  },
{ 6439, 6461, 6485, 6510, 6536, 6564, 6593  },
{ 6447, 6470, 6493, 6518, 6545, 6572, 6601  },
{ 6456, 6478, 6502, 6526, 6553, 6580, 6609  },
{ 6464, 6486, 6510, 6535, 6561, 6588, 6617  },
{ 6472, 6495, 6518, 6543, 6569, 6597, 6625  },
{ 6481, 6503, 6526, 6551, 6577, 6605, 6633  },
{ 6489, 6511, 6535, 6559, 6585, 6613, 6641  },
{ 6497, 6519, 6543, 6567, 6593, 6621, 6649  },
{ 6506, 6528, 6551, 6576, 6602, 6629, 6657  },
{ 6514, 6536, 6559, 6584, 6610, 6637, 6665  },
{ 6522, 6544, 6567, 6592, 6618, 6645, 6673  },
{ 6531, 6552, 6576, 6600, 6626, 6653, 6681  },
{ 6539, 6561, 6584, 6608, 6634, 6661, 6689  },
{ 6547, 6569, 6592, 6616, 6642, 6669, 6697  },
{ 6555, 6577, 6600, 6624, 6650, 6677, 6705  },
{ 6563, 6585, 6608, 6632, 6658, 6684, 6713  },
{ 6571, 6593, 6616, 6640, 6666, 6692, 6720  },
{ 6580, 6601, 6624, 6648, 6674, 6700, 6728  },
{ 6588, 6609, 6632, 6656, 6681, 6708, 6736  },
{ 6596, 6617, 6640, 6664, 6689, 6716, 6744  },
{ 6604, 6625, 6648, 6672, 6697, 6724, 6752  },
{ 6612, 6633, 6656, 6680, 6705, 6732, 6759  },
{ 6620, 6641, 6664, 6688, 6713, 6739, 6767  },
{ 6628, 6649, 6672, 6696, 6721, 6747, 6775  },
{ 6636, 6657, 6680, 6704, 6729, 6755, 6782  },
{ 6644, 6665, 6688, 6711, 6736, 6763, 6790  },
{ 6652, 6673, 6696, 6719, 6744, 6770, 6798  },
{ 6660, 6681, 6703, 6727, 6752, 6778, 6805  },
{ 6668, 6689, 6711, 6735, 6760, 6786, 6813  },
{ 6676, 6697, 6719, 6743, 6767, 6793, 6821  },
{ 6684, 6705, 6727, 6750, 6775, 6801, 6828  },
{ 6692, 6713, 6735, 6758, 6783, 6809, 6836  },
{ 6700, 6720, 6742, 6766, 6790, 6816, 6843  },
{ 6707, 6728, 6750, 6774, 6798, 6824, 6851  },
{ 6715, 6736, 6758, 6781, 6806, 6832, 6859  },
{ 6723, 6744, 6766, 6789, 6813, 6839, 6866  },
{ 6731, 6752, 6773, 6797, 6821, 6847, 6874  },
{ 6739, 6759, 6781, 6804, 6829, 6854, 6881  },
{ 6746, 6767, 6789, 6812, 6836, 6862, 6889  },
{ 6754, 6775, 6797, 6820, 6844, 6869, 6896  },
{ 6762, 6782, 6804, 6827, 6851, 6877, 6904  },
{ 6770, 6790, 6812, 6835, 6859, 6884, 6911  },
{ 6777, 6798, 6819, 6842, 6866, 6892, 6918  },
{ 6785, 6805, 6827, 6850, 6874, 6899, 6926  },
{ 6793, 6813, 6835, 6857, 6881, 6907, 6933  },
{ 6800, 6821, 6842, 6865, 6889, 6914, 6941  },
{ 6808, 6828, 6850, 6872, 6896, 6922, 6948  },
{ 6816, 6836, 6857, 6880, 6904, 6929, 6955  },
{ 6823, 6843, 6865, 6887, 6911, 6936, 6963  },
{ 6831, 6851, 6872, 6895, 6919, 6944, 6970  },
{ 6838, 6859, 6880, 6902, 6926, 6951, 6977  },
{ 6846, 6866, 6887, 6910, 6934, 6958, 6985  },
{ 6854, 6874, 6895, 6917, 6941, 6966, 6992  },
{ 6861, 6881, 6902, 6925, 6948, 6973, 6999  },
{ 6869, 6889, 6910, 6932, 6956, 6980, 7006  },
{ 6876, 6896, 6917, 6939, 6963, 6988, 7014  },
{ 6884, 6904, 6925, 6947, 6970, 6995, 7021  },
{ 6891, 6911, 6932, 6954, 6978, 7002, 7028  },
{ 6899, 6918, 6939, 6962, 6985, 7009, 7035  },
{ 6906, 6926, 6947, 6969, 6992, 7017, 7042  },
{ 6913, 6933, 6954, 6976, 6999, 7024, 7050  },
{ 6921, 6941, 6961, 6983, 7007, 7031, 7057  },
{ 6928, 6948, 6969, 6991, 7014, 7038, 7064  },
{ 6936, 6955, 6976, 6998, 7021, 7046, 7071  },
{ 6943, 6963, 6983, 7005, 7028, 7053, 7078  },
{ 6950, 6970, 6991, 7013, 7036, 7060, 7085  },
{ 6958, 6977, 6998, 7020, 7043, 7067, 7092  },
{ 6965, 6985, 7005, 7027, 7050, 7074, 7100  },
{ 6972, 6992, 7012, 7034, 7057, 7081, 7107  },
{ 6980, 6999, 7020, 7041, 7064, 7088, 7114  },
{ 6987, 7006, 7027, 7049, 7071, 7095, 7121  },
{ 6994, 7014, 7034, 7056, 7079, 7103, 7128  },
{ 7002, 7021, 7041, 7063, 7086, 7110, 7135  },
{ 7009, 7028, 7048, 7070, 7093, 7117, 7142  },
{ 7016, 7035, 7056, 7077, 7100, 7124, 7149  },
{ 7023, 7042, 7063, 7084, 7107, 7131, 7156  },
{ 7031, 7050, 7070, 7091, 7114, 7138, 7163  },
{ 7038, 7057, 7077, 7098, 7121, 7145, 7170  },
{ 7045, 7064, 7084, 7106, 7128, 7152, 7177  },
{ 7052, 7071, 7091, 7113, 7135, 7159, 7184  },
{ 7059, 7078, 7098, 7120, 7142, 7166, 7190  },
{ 7066, 7085, 7105, 7127, 7149, 7173, 7197  },
{ 7074, 7092, 7112, 7134, 7156, 7180, 7204  },
{ 7081, 7100, 7120, 7141, 7163, 7187, 7211  },
{ 7088, 7107, 7127, 7148, 7170, 7193, 7218  },
{ 7095, 7114, 7134, 7155, 7177, 7200, 7225  },
{ 7102, 7121, 7141, 7162, 7184, 7207, 7232  },
{ 7109, 7128, 7148, 7169, 7191, 7214, 7239  },
{ 7116, 7135, 7155, 7176, 7198, 7221, 7245  },
{ 7123, 7142, 7162, 7182, 7205, 7228, 7252  },
{ 7130, 7149, 7169, 7189, 7211, 7235, 7259  },
{ 7137, 7156, 7175, 7196, 7218, 7242, 7266  },
{ 7144, 7163, 7182, 7203, 7225, 7248, 7273  },
{ 7151, 7170, 7189, 7210, 7232, 7255, 7279  },
{ 7158, 7177, 7196, 7217, 7239, 7262, 7286  },
{ 7165, 7184, 7203, 7224, 7246, 7269, 7293  },
{ 7172, 7190, 7210, 7231, 7253, 7276, 7300  },
{ 7179, 7197, 7217, 7238, 7259, 7282, 7306  },
{ 7186, 7204, 7224, 7244, 7266, 7289, 7313  },
{ 7193, 7211, 7231, 7251, 7273, 7296, 7320  },
{ 7200, 7218, 7237, 7258, 7280, 7302, 7326  },
{ 7207, 7225, 7244, 7265, 7286, 7309, 7333  },
{ 7214, 7232, 7251, 7272, 7293, 7316, 7340  },
{ 7220, 7239, 7258, 7278, 7300, 7323, 7346  },
{ 7227, 7245, 7265, 7285, 7307, 7329, 7353  },
{ 7234, 7252, 7272, 7292, 7313, 7336, 7360  },
{ 7241, 7259, 7278, 7299, 7320, 7343, 7366  },
{ 7248, 7266, 7285, 7305, 7327, 7349, 7373  },
{ 7255, 7273, 7292, 7312, 7333, 7356, 7380  },
{ 7261, 7279, 7299, 7319, 7340, 7363, 7386  },
{ 7268, 7286, 7305, 7325, 7347, 7369, 7393  },
{ 7275, 7293, 7312, 7332, 7353, 7376, 7399  },
{ 7282, 7300, 7319, 7339, 7360, 7382, 7406  },
{ 7288, 7306, 7325, 7345, 7367, 7389, 7412  },
{ 7295, 7313, 7332, 7352, 7373, 7396, 7419  },
{ 7302, 7320, 7339, 7359, 7380, 7402, 7426  },
{ 7309, 7326, 7345, 7365, 7386, 7409, 7432  },
{ 7315, 7333, 7352, 7372, 7393, 7415, 7439  },
{ 7322, 7340, 7359, 7379, 7400, 7422, 7445  },
{ 7329, 7346, 7365, 7385, 7406, 7428, 7452  },
{ 7335, 7353, 7372, 7392, 7413, 7435, 7458  },
{ 7342, 7360, 7379, 7398, 7419, 7441, 7464  },
{ 7349, 7366, 7385, 7405, 7426, 7448, 7471  },
{ 7355, 7373, 7392, 7411, 7432, 7454, 7477  },
{ 7362, 7380, 7398, 7418, 7439, 7461, 7484  },
{ 7369, 7386, 7405, 7425, 7445, 7467, 7490  },
{ 7375, 7393, 7411, 7431, 7452, 7474, 7497  },
{ 7382, 7399, 7418, 7438, 7458, 7480, 7503  },
{ 7388, 7406, 7424, 7444, 7465, 7487, 7509  },
{ 7395, 7412, 7431, 7451, 7471, 7493, 7516  },
{ 7402, 7419, 7437, 7457, 7478, 7499, 7522  },
{ 7408, 7426, 7444, 7463, 7484, 7506, 7529  },
{ 7415, 7432, 7450, 7470, 7491, 7512, 7535  },
{ 7421, 7439, 7457, 7476, 7497, 7519, 7541  },
{ 7428, 7445, 7463, 7483, 7503, 7525, 7548  },
{ 7434, 7452, 7470, 7489, 7510, 7531, 7554  },
{ 7441, 7458, 7476, 7496, 7516, 7538, 7560  },
{ 7447, 7464, 7483, 7502, 7523, 7544, 7567  },
{ 7454, 7471, 7489, 7509, 7529, 7550, 7573  },
{ 7460, 7477, 7496, 7515, 7535, 7557, 7579  },
{ 7467, 7484, 7502, 7521, 7542, 7563, 7585  },
{ 7473, 7490, 7508, 7528, 7548, 7569, 7592  },
{ 7480, 7497, 7515, 7534, 7554, 7576, 7598  },
{ 7486, 7503, 7521, 7540, 7561, 7582, 7604  },
{ 7492, 7509, 7528, 7547, 7567, 7588, 7611  },
{ 7499, 7516, 7534, 7553, 7573, 7594, 7617  },
{ 7505, 7522, 7540, 7559, 7579, 7601, 7623  },
{ 7512, 7529, 7547, 7566, 7586, 7607, 7629  },
{ 7518, 7535, 7553, 7572, 7592, 7613, 7635  },
{ 7524, 7541, 7559, 7578, 7598, 7619, 7642  },
{ 7531, 7548, 7566, 7585, 7605, 7626, 7648  },
{ 7537, 7554, 7572, 7591, 7611, 7632, 7654  },
{ 7543, 7560, 7578, 7597, 7617, 7638, 7660  },
{ 7550, 7567, 7584, 7603, 7623, 7644, 7666  },
{ 7556, 7573, 7591, 7610, 7629, 7650, 7672  },
{ 7562, 7579, 7597, 7616, 7636, 7657, 7679  },
{ 7569, 7585, 7603, 7622, 7642, 7663, 7685  },
{ 7575, 7592, 7609, 7628, 7648, 7669, 7691  },
{ 7581, 7598, 7616, 7634, 7654, 7675, 7697  },
{ 7588, 7604, 7622, 7641, 7660, 7681, 7703  },
{ 7594, 7611, 7628, 7647, 7667, 7687, 7709  },
{ 7600, 7617, 7634, 7653, 7673, 7693, 7715  },
{ 7606, 7623, 7641, 7659, 7679, 7700, 7721  },
{ 7613, 7629, 7647, 7665, 7685, 7706, 7727  },
{ 7619, 7635, 7653, 7672, 7691, 7712, 7733  },
{ 7625, 7642, 7659, 7678, 7697, 7718, 7740  },
{ 7631, 7648, 7665, 7684, 7703, 7724, 7746  },
{ 7638, 7654, 7671, 7690, 7709, 7730, 7752  },
{ 7644, 7660, 7678, 7696, 7716, 7736, 7758  },
{ 7650, 7666, 7684, 7702, 7722, 7742, 7764  },
{ 7656, 7672, 7690, 7708, 7728, 7748, 7770  },
{ 7662, 7679, 7696, 7714, 7734, 7754, 7776  },
{ 7668, 7685, 7702, 7720, 7740, 7760, 7782  },
{ 7675, 7691, 7708, 7726, 7746, 7766, 7788  },
{ 7681, 7697, 7714, 7733, 7752, 7772, 7794  },
{ 7687, 7703, 7720, 7739, 7758, 7778, 7800  },
{ 7693, 7709, 7726, 7745, 7764, 7784, 7806  },
{ 7699, 7715, 7732, 7751, 7770, 7790, 7812  },
{ 7705, 7721, 7739, 7757, 7776, 7796, 7817  },
{ 7711, 7727, 7745, 7763, 7782, 7802, 7823  },
{ 7717, 7733, 7751, 7769, 7788, 7808, 7829  },
{ 7723, 7740, 7757, 7775, 7794, 7814, 7835  },
{ 7729, 7746, 7763, 7781, 7800, 7820, 7841  },
{ 7736, 7752, 7769, 7787, 7806, 7826, 7847  },
{ 7742, 7758, 7775, 7793, 7812, 7832, 7853  },
{ 7748, 7764, 7781, 7799, 7818, 7838, 7859  },
{ 7754, 7770, 7787, 7805, 7824, 7844, 7865  },
{ 7760, 7776, 7793, 7811, 7830, 7850, 7871  },
{ 7766, 7782, 7799, 7817, 7836, 7856, 7877  },
{ 7772, 7788, 7805, 7823, 7841, 7861, 7882  },
{ 7778, 7794, 7811, 7828, 7847, 7867, 7888  },
{ 7784, 7800, 7817, 7834, 7853, 7873, 7894  },
{ 7790, 7806, 7822, 7840, 7859, 7879, 7900  },
{ 7796, 7812, 7828, 7846, 7865, 7885, 7906  },
{ 7802, 7817, 7834, 7852, 7871, 7891, 7912  },
{ 7808, 7823, 7840, 7858, 7877, 7897, 7917  },
{ 7814, 7829, 7846, 7864, 7883, 7902, 7923  },
{ 7820, 7835, 7852, 7870, 7888, 7908, 7929  },
{ 7825, 7841, 7858, 7876, 7894, 7914, 7935  },
{ 7831, 7847, 7864, 7881, 7900, 7920, 7941  },
{ 7837, 7853, 7870, 7887, 7906, 7926, 7946  },
{ 7843, 7859, 7876, 7893, 7912, 7931, 7952  },
{ 7849, 7865, 7881, 7899, 7918, 7937, 7958  },
{ 7855, 7871, 7887, 7905, 7923, 7943, 7964  },
{ 7861, 7877, 7893, 7911, 7929, 7949, 7969  },
{ 7867, 7882, 7899, 7916, 7935, 7954, 7975  },
{ 7873, 7888, 7905, 7922, 7941, 7960, 7981  },
{ 7878, 7894, 7911, 7928, 7947, 7966, 7986  },
{ 7884, 7900, 7916, 7934, 7952, 7972, 7992  },
{ 7890, 7906, 7922, 7940, 7958, 7977, 7998  },
{ 7896, 7912, 7928, 7945, 7964, 7983, 8004  },
{ 7902, 7917, 7934, 7951, 7970, 7989, 8009  },
{ 7908, 7923, 7940, 7957, 7975, 7995, 8015  },
{ 7914, 7929, 7945, 7963, 7981, 8000, 8021  },
{ 7919, 7935, 7951, 7968, 7987, 8006, 8026  },
{ 7925, 7941, 7957, 7974, 7992, 8012, 8032  },
{ 7931, 7946, 7963, 7980, 7998, 8017, 8038  },
{ 7937, 7952, 7968, 7986, 8004, 8023, 8043  }};


const unsigned int XTATemps[NROFTAELEMENTS]={2782,  2882, 2982, 3082, 3182, 3282, 3382};
const unsigned int YADValues[NROFADELEMENTS]={0,  64, 128,  192,  256,  320,  384,  448,  512,  576,  640,  704,  768,  832,  896,  960,  1024, 1088, 1152, 1216, 1280, 1344, 1408, 1472, 1536, 1600, 1664, 1728, 1792, 1856, 1920, 1984, 2048, 2112, 2176, 2240, 2304, 2368, 2432, 2496, 2560, 2624, 2688, 2752, 2816, 2880, 2944, 3008, 3072, 3136, 3200, 3264, 3328, 3392, 3456, 3520, 3584, 3648, 3712, 3776, 3840, 3904, 3968, 4032, 4096, 4160, 4224, 4288, 4352, 4416, 4480, 4544, 4608, 4672, 4736, 4800, 4864, 4928, 4992, 5056, 5120, 5184, 5248, 5312, 5376, 5440, 5504, 5568, 5632, 5696, 5760, 5824, 5888, 5952, 6016, 6080, 6144, 6208, 6272, 6336, 6400, 6464, 6528, 6592, 6656, 6720, 6784, 6848, 6912, 6976, 7040, 7104, 7168, 7232, 7296, 7360, 7424, 7488, 7552, 7616, 7680, 7744, 7808, 7872, 7936, 8000, 8064, 8128, 8192, 8256, 8320, 8384, 8448, 8512, 8576, 8640, 8704, 8768, 8832, 8896, 8960, 9024, 9088, 9152, 9216, 9280, 9344, 9408, 9472, 9536, 9600, 9664, 9728, 9792, 9856, 9920, 9984, 10048,  10112,  10176,  10240,  10304,  10368,  10432,  10496,  10560,  10624,  10688,  10752,  10816,  10880,  10944,  11008,  11072,  11136,  11200,  11264,  11328,  11392,  11456,  11520,  11584,  11648,  11712,  11776,  11840,  11904,  11968,  12032,  12096,  12160,  12224,  12288,  12352,  12416,  12480,  12544,  12608,  12672,  12736,  12800,  12864,  12928,  12992,  13056,  13120,  13184,  13248,  13312,  13376,  13440,  13504,  13568,  13632,  13696,  13760,  13824,  13888,  13952,  14016,  14080,  14144,  14208,  14272,  14336,  14400,  14464,  14528,  14592,  14656,  14720,  14784,  14848,  14912,  14976,  15040,  15104,  15168,  15232,  15296,  15360,  15424,  15488,  15552,  15616,  15680,  15744,  15808,  15872,  15936,  16000,  16064,  16128,  16192,  16256,  16320,  16384,  16448,  16512,  16576,  16640,  16704,  16768,  16832,  16896,  16960,  17024,  17088,  17152,  17216,  17280,  17344,  17408,  17472,  17536,  17600,  17664,  17728,  17792,  17856,  17920,  17984,  18048,  18112,  18176,  18240,  18304,  18368,  18432,  18496,  18560,  18624,  18688,  18752,  18816,  18880,  18944,  19008,  19072,  19136,  19200,  19264,  19328,  19392,  19456,  19520,  19584,  19648,  19712,  19776,  19840,  19904,  19968,  20032,  20096,  20160,  20224,  20288,  20352,  20416,  20480,  20544,  20608,  20672,  20736,  20800,  20864,  20928,  20992,  21056,  21120,  21184,  21248,  21312,  21376,  21440,  21504,  21568,  21632,  21696,  21760,  21824,  21888,  21952,  22016,  22080,  22144,  22208,  22272,  22336,  22400,  22464,  22528,  22592,  22656,  22720,  22784,  22848,  22912,  22976,  23040,  23104,  23168,  23232,  23296,  23360,  23424,  23488,  23552,  23616,  23680,  23744,  23808,  23872,  23936,  24000,  24064,  24128,  24192,  24256,  24320,  24384,  24448,  24512,  24576,  24640,  24704,  24768,  24832,  24896,  24960,  25024,  25088,  25152,  25216,  25280,  25344,  25408,  25472,  25536,  25600,  25664,  25728,  25792,  25856,  25920,  25984,  26048,  26112,  26176,  26240,  26304,  26368,  26432,  26496,  26560,  26624,  26688,  26752,  26816,  26880,  26944,  27008,  27072,  27136,  27200,  27264,  27328,  27392,  27456,  27520,  27584,  27648,  27712,  27776,  27840,  27904,  27968,  28032,  28096,  28160,  28224,  28288,  28352,  28416,  28480,  28544,  28608,  28672,  28736,  28800,  28864,  28928,  28992,  29056,  29120,  29184,  29248,  29312,  29376,  29440,  29504,  29568,  29632,  29696,  29760,  29824,  29888,  29952,  30016,  30080};

#endif // for #ifndef  _def_H
