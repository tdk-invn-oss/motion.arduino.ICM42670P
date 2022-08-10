/*
 *________________________________________________________________________________________________________
 * Copyright (c) 2017 InvenSense Inc. All rights reserved.
 *
 * This software, related documentation and any modifications thereto (collectively "Software") is subject
 * to InvenSense and its licensors intellectual property rights under U.S. and international copyright 
 * and other intellectual property rights laws.
 *
 * InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
 * and any use, reproduction, disclosure or distribution of the Software without an express license agreement
 * from InvenSense is strictly prohibited.
 *
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, THE SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * EXCEPT AS OTHERWISE PROVIDED IN A LICENSE AGREEMENT BETWEEN THE PARTIES, IN NO EVENT SHALL
 * INVENSENSE BE LIABLE FOR ANY DIRECT, SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
   OF THE SOFTWARE.
 * ________________________________________________________________________________________________________
 */
#ifndef _INV_IMU_REGMAP_INTERNAL_H_
#define _INV_IMU_REGMAP_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @file inv_imu_regmap_internal.h
 * File exposing the device register map
 */

#include <stdint.h>

/* forward declaration */
struct inv_imu_device;



/* ----------------------------------------------------------------------------
 * Device Register map
 *
 * Next macros defines address for all registers as listed by device 
 * datasheet.
 * Macros name is <REGISTER_NAME> with REGISTER_NAME being the name of
 * the corresponding register in datasheet.
 * Note that macro name is <REGISTER_NAME>_Bx with x being the bank 
 * number for registers that are in bank 1 and further (suffix is ommitted for 
 * bank 0 registers)
 * ---------------------------------------------------------------------------- */

/* BANK0 */
#define MISC_1                                                             0x10000
#define CHIP_CONFIG_REG                                                    0x10001
#define SIGNAL_PATH_RESET                                                  0x10002
#define DRIVE_CONFIG_REG1                                                  0x10003
#define DRIVE_CONFIG_REG2                                                  0x10004
#define DRIVE_CONFIG_REG3                                                  0x10005
#define INT_CONFIG_REG                                                     0x10006
#define ODRGRID0                                                           0x10007
#define ODRGRID1                                                           0x10008
#define TEMP_DATA0_UI                                                      0x10009
#define TEMP_DATA1_UI                                                      0x1000a
#define ACCEL_DATA_X0_UI                                                   0x1000b
#define ACCEL_DATA_X1_UI                                                   0x1000c
#define ACCEL_DATA_Y0_UI                                                   0x1000d
#define ACCEL_DATA_Y1_UI                                                   0x1000e
#define ACCEL_DATA_Z0_UI                                                   0x1000f
#define ACCEL_DATA_Z1_UI                                                   0x10010
#define GYRO_DATA_X0_UI                                                    0x10011
#define GYRO_DATA_X1_UI                                                    0x10012
#define GYRO_DATA_Y0_UI                                                    0x10013
#define GYRO_DATA_Y1_UI                                                    0x10014
#define GYRO_DATA_Z0_UI                                                    0x10015
#define GYRO_DATA_Z1_UI                                                    0x10016
#define TMST_FSYNC1                                                        0x10017
#define TMST_FSYNC2                                                        0x10018
#define ODR_LP_STATUS                                                      0x10019
#define APEX_DATA4                                                         0x1001d
#define APEX_DATA5                                                         0x1001e
#define PWR_MGMT_0                                                         0x1001f
#define GYRO_CONFIG0                                                       0x10020
#define ACCEL_CONFIG0                                                      0x10021
#define TEMP_CONFIG0                                                       0x10022
#define GYRO_CONFIG1                                                       0x10023
#define ACCEL_CONFIG1                                                      0x10024
#define APEX_CONFIG0                                                       0x10025
#define APEX_CONFIG1                                                       0x10026
#define WOM_CONFIG                                                         0x10027
#define FIFO_CONFIG1                                                       0x10028
#define FIFO_CONFIG2                                                       0x10029
#define FIFO_CONFIG3                                                       0x1002a
#define INT_SOURCE0                                                        0x1002b
#define INT_SOURCE1                                                        0x1002c
#define INT_SOURCE3                                                        0x1002d
#define INT_SOURCE4                                                        0x1002e
#define FIFO_LOST_PKT0                                                     0x1002f
#define FIFO_LOST_PKT1                                                     0x10030
#define APEX_DATA0                                                         0x10031
#define APEX_DATA1                                                         0x10032
#define APEX_DATA2                                                         0x10033
#define APEX_DATA3                                                         0x10034
#define INTF_CONFIG0                                                       0x10035
#define INTF_CONFIG1                                                       0x10036
#define SCAN1                                                              0x10037
#define CKG_STATUS                                                         0x10038
#define INT_STATUS_DRDY                                                    0x10039
#define INT_STATUS                                                         0x1003a
#define INT_STATUS2                                                        0x1003b
#define INT_STATUS3                                                        0x1003c
#define FIFO_BYTE_COUNT1                                                   0x1003d
#define FIFO_BYTE_COUNT2                                                   0x1003e
#define FIFO_DATA_REG                                                      0x1003f
#define GYR_BIAS_CFG1                                                      0x10046
#define DIG_CLK_CFG1                                                       0x10047
#define AMP_GDC2V_CFG0                                                     0x10048
#define DRV_GYR_CFG4                                                       0x10049
#define PLL_LP_CFG0                                                        0x1004a
#define INTF_CONFIG2                                                       0x1004b
#define INTF_CONFIG3                                                       0x1004c
#define SREG_SPARE1                                                        0x1006e
#define SREG_SPARE2                                                        0x1006f
#define SREG_SPARE3                                                        0x10070
#define SREG_SPARE4                                                        0x10071
#define WHO_AM_I                                                           0x10075
#define BLK_SEL_W                                                          0x10079
#define MADDR_W                                                            0x1007a
#define M_W                                                                0x1007b
#define BLK_SEL_R                                                          0x1007c
#define MADDR_R                                                            0x1007d
#define M_R                                                                0x1007e

/* MREG_BAR */
#define TMP_BAR_0_BYTE_0_MREG_BAR                                          0x1800
#define TMP_BAR_0_BYTE_1_MREG_BAR                                          0x1801
#define TMP_BAR_0_BYTE_2_MREG_BAR                                          0x1802
#define TMP_BAR_0_BYTE_3_MREG_BAR                                          0x1803
#define GYRO_DC2V_BAR_1_BYTE_0_MREG_BAR                                    0x1804
#define GYRO_DC2V_BAR_1_BYTE_1_MREG_BAR                                    0x1805
#define GYRO_DC2V_BAR_1_BYTE_2_MREG_BAR                                    0x1806
#define GYRO_DC2V_BAR_1_BYTE_3_MREG_BAR                                    0x1807
#define GYRO_CP_BAR_2_BYTE_0_MREG_BAR                                      0x1808
#define GYRO_CP_BAR_2_BYTE_1_MREG_BAR                                      0x1809
#define GYRO_CP_BAR_2_BYTE_2_MREG_BAR                                      0x180a
#define GYRO_CP_BAR_2_BYTE_3_MREG_BAR                                      0x180b
#define MB_AREG_BAR_3_BYTE_0_MREG_BAR                                      0x180c
#define MB_AREG_BAR_4_BYTE_0_MREG_BAR                                      0x1810
#define MB_AREG_BAR_4_BYTE_1_MREG_BAR                                      0x1811
#define MB_CORE_BAR_5_BYTE_0_MREG_BAR                                      0x1814
#define MB_CORE_BAR_5_BYTE_1_MREG_BAR                                      0x1815
#define MB_CORE_BAR_5_BYTE_2_MREG_BAR                                      0x1816
#define MB_CORE_BAR_5_BYTE_3_MREG_BAR                                      0x1817
#define MB_CORE_BAR_6_BYTE_0_MREG_BAR                                      0x1818
#define MB_CORE_BAR_6_BYTE_1_MREG_BAR                                      0x1819
#define MB_CORE_BAR_6_BYTE_2_MREG_BAR                                      0x181a
#define MB_CORE_BAR_6_BYTE_3_MREG_BAR                                      0x181b
#define MB_CORE_BAR_7_BYTE_0_MREG_BAR                                      0x181c
#define MB_CORE_BAR_7_BYTE_1_MREG_BAR                                      0x181d
#define MB_CORE_BAR_7_BYTE_2_MREG_BAR                                      0x181e
#define ACC_CP_BAR_8_BYTE_0_MREG_BAR                                       0x1820
#define ACC_BIAS_BAR_9_BYTE_0_MREG_BAR                                     0x1824
#define ACC_BIAS_BAR_9_BYTE_1_MREG_BAR                                     0x1825
#define ACC_BIAS_BAR_9_BYTE_2_MREG_BAR                                     0x1826
#define ACC_BIAS_BAR_9_BYTE_3_MREG_BAR                                     0x1827
#define MB_DREG_BAR_10_BYTE_0_MREG_BAR                                     0x1828
#define MB_DREG_BAR_10_BYTE_1_MREG_BAR                                     0x1829
#define AMP_GSXYZ_BAR_11_BYTE_0_MREG_BAR                                   0x182c
#define AMP_GSXYZ_BAR_11_BYTE_1_MREG_BAR                                   0x182d
#define AMP_GSXYZ_BAR_11_BYTE_2_MREG_BAR                                   0x182e
#define AMP_GSXYZ_BAR_11_BYTE_3_MREG_BAR                                   0x182f
#define AMP_GSXYZ_BAR_12_BYTE_0_MREG_BAR                                   0x1830
#define AMP_GSXYZ_BAR_12_BYTE_1_MREG_BAR                                   0x1831
#define AMP_GSXYZ_BAR_12_BYTE_2_MREG_BAR                                   0x1832
#define AMP_GSXYZ_BAR_12_BYTE_3_MREG_BAR                                   0x1833
#define AMP_GSXYZ_BAR_13_BYTE_0_MREG_BAR                                   0x1834
#define AMP_GSXYZ_BAR_13_BYTE_1_MREG_BAR                                   0x1835
#define AMP_GSXYZ_BAR_13_BYTE_2_MREG_BAR                                   0x1836
#define AMP_GSXYZ_BAR_13_BYTE_3_MREG_BAR                                   0x1837
#define AMP_GSXYZ_BAR_14_BYTE_0_MREG_BAR                                   0x1838
#define AMP_GSXYZ_BAR_14_BYTE_1_MREG_BAR                                   0x1839
#define AMP_GSXYZ_BAR_14_BYTE_2_MREG_BAR                                   0x183a
#define AMP_GSXYZ_BAR_14_BYTE_3_MREG_BAR                                   0x183b
#define AMP_GSXYZ_BAR_15_BYTE_0_MREG_BAR                                   0x183c
#define AMP_GSXYZ_BAR_15_BYTE_1_MREG_BAR                                   0x183d
#define AMP_GSXYZ_BAR_15_BYTE_2_MREG_BAR                                   0x183e
#define AMP_GSXYZ_BAR_15_BYTE_3_MREG_BAR                                   0x183f
#define AMP_GSXYZ_BAR_16_BYTE_0_MREG_BAR                                   0x1840
#define AMP_GSXYZ_BAR_16_BYTE_1_MREG_BAR                                   0x1841
#define AMP_GSXYZ_BAR_16_BYTE_2_MREG_BAR                                   0x1842
#define AMP_GSXYZ_BAR_16_BYTE_3_MREG_BAR                                   0x1843
#define ACC_XYZ_BAR_18_BYTE_0_MREG_BAR                                     0x1848
#define ACC_XYZ_BAR_18_BYTE_1_MREG_BAR                                     0x1849
#define ACC_XYZ_BAR_18_BYTE_2_MREG_BAR                                     0x184a
#define ACC_XYZ_BAR_18_BYTE_3_MREG_BAR                                     0x184b
#define ACC_XYZ_BAR_19_BYTE_0_MREG_BAR                                     0x184c
#define ACC_XYZ_BAR_19_BYTE_1_MREG_BAR                                     0x184d
#define ACC_XYZ_BAR_19_BYTE_2_MREG_BAR                                     0x184e
#define ACC_XYZ_BAR_19_BYTE_3_MREG_BAR                                     0x184f
#define ACC_XYZ_BAR_20_BYTE_0_MREG_BAR                                     0x1850
#define ACC_XYZ_BAR_20_BYTE_1_MREG_BAR                                     0x1851
#define ACC_XYZ_BAR_20_BYTE_2_MREG_BAR                                     0x1852
#define ACC_XYZ_BAR_20_BYTE_3_MREG_BAR                                     0x1853
#define ACC_XYZ_BAR_21_BYTE_0_MREG_BAR                                     0x1854
#define ACC_XYZ_BAR_21_BYTE_1_MREG_BAR                                     0x1855
#define ACC_XYZ_BAR_21_BYTE_2_MREG_BAR                                     0x1856
#define ACC_XYZ_BAR_21_BYTE_3_MREG_BAR                                     0x1857
#define ACC_XYZ_BAR_22_BYTE_0_MREG_BAR                                     0x1858
#define ACC_XYZ_BAR_22_BYTE_1_MREG_BAR                                     0x1859
#define ACC_XYZ_BAR_22_BYTE_2_MREG_BAR                                     0x185a
#define ACC_XYZ_BAR_22_BYTE_3_MREG_BAR                                     0x185b
#define ACC_XYZ_BAR_23_BYTE_0_MREG_BAR                                     0x185c
#define ACC_XYZ_BAR_23_BYTE_1_MREG_BAR                                     0x185d
#define ACC_XYZ_BAR_23_BYTE_2_MREG_BAR                                     0x185e
#define ACC_XYZ_BAR_23_BYTE_3_MREG_BAR                                     0x185f
#define DMD_GCT_BAR_24_BYTE_0_MREG_BAR                                     0x1860
#define DMD_GCT_BAR_24_BYTE_1_MREG_BAR                                     0x1861
#define DMD_GCT_BAR_24_BYTE_2_MREG_BAR                                     0x1862
#define DMD_GCT_BAR_24_BYTE_3_MREG_BAR                                     0x1863
#define DMD_GCT_BAR_25_BYTE_0_MREG_BAR                                     0x1864
#define DMD_GCT_BAR_25_BYTE_1_MREG_BAR                                     0x1865
#define DMD_GCT_BAR_25_BYTE_2_MREG_BAR                                     0x1866
#define DMD_GCT_BAR_25_BYTE_3_MREG_BAR                                     0x1867
#define DMD_GCT_BAR_26_BYTE_0_MREG_BAR                                     0x1868
#define DMD_GCT_BAR_26_BYTE_1_MREG_BAR                                     0x1869
#define DMD_GCT_BAR_26_BYTE_2_MREG_BAR                                     0x186a
#define DMD_GCT_BAR_26_BYTE_3_MREG_BAR                                     0x186b
#define DRV_GYR_BAR_27_BYTE_0_MREG_BAR                                     0x186c
#define DRV_GYR_BAR_27_BYTE_1_MREG_BAR                                     0x186d
#define DRV_GYR_BAR_27_BYTE_2_MREG_BAR                                     0x186e
#define DRV_GYR_BAR_27_BYTE_3_MREG_BAR                                     0x186f
#define DRV_GYR_BAR_28_BYTE_0_MREG_BAR                                     0x1870
#define DRV_GYR_BAR_28_BYTE_1_MREG_BAR                                     0x1871
#define DRV_GYR_BAR_29_BYTE_0_MREG_BAR                                     0x1874
#define DRV_GYR_BAR_29_BYTE_1_MREG_BAR                                     0x1875
#define DRV_GYR_BAR_29_BYTE_2_MREG_BAR                                     0x1876
#define DRV_GYR_BAR_29_BYTE_3_MREG_BAR                                     0x1877
#define DRV_GYR_BAR_30_BYTE_0_MREG_BAR                                     0x1878
#define DRV_GYR_BAR_30_BYTE_1_MREG_BAR                                     0x1879
#define DRV_GYR_BAR_30_BYTE_2_MREG_BAR                                     0x187a
#define DRV_GYR_BAR_30_BYTE_3_MREG_BAR                                     0x187b
#define PLL_BAR_31_BYTE_0_MREG_BAR                                         0x187c
#define PLL_BAR_31_BYTE_1_MREG_BAR                                         0x187d
#define PLL_BAR_31_BYTE_2_MREG_BAR                                         0x187e
#define PLL_BAR_31_BYTE_3_MREG_BAR                                         0x187f
#define PLL_BAR_32_BYTE_0_MREG_BAR                                         0x1880
#define PLL_BAR_32_BYTE_1_MREG_BAR                                         0x1881
#define PLL_BAR_32_BYTE_2_MREG_BAR                                         0x1882
#define PLL_BAR_32_BYTE_3_MREG_BAR                                         0x1883
#define PLL_BAR_33_BYTE_0_MREG_BAR                                         0x1884
#define PLL_BAR_33_BYTE_1_MREG_BAR                                         0x1885

/* MMEM_SIGP */
#define ACCEL_X_GOS_0_MMEM_SIGP                                            0x100a
#define ACCEL_X_GOS_1_MMEM_SIGP                                            0x100b
#define ACCEL_X_GOS_2_MMEM_SIGP                                            0x100c
#define ACCEL_X_GOS_3_MMEM_SIGP                                            0x100d
#define ACCEL_X_GOS_4_MMEM_SIGP                                            0x100e
#define ACCEL_X_GOS_5_MMEM_SIGP                                            0x100f
#define ACCEL_X_GOS_6_MMEM_SIGP                                            0x1010
#define ACCEL_X_GOS_7_MMEM_SIGP                                            0x1011
#define ACCEL_X_GOS_8_MMEM_SIGP                                            0x1012
#define ACCEL_X_GOS_9_MMEM_SIGP                                            0x1013
#define ACCEL_X_GOS_10_MMEM_SIGP                                           0x1014
#define ACCEL_X_GOS_11_MMEM_SIGP                                           0x1015
#define ACCEL_X_GOS_12_MMEM_SIGP                                           0x1016
#define ACCEL_X_GOS_13_MMEM_SIGP                                           0x1017
#define ACCEL_Y_GOS_0_MMEM_SIGP                                            0x1022
#define ACCEL_Y_GOS_1_MMEM_SIGP                                            0x1023
#define ACCEL_Y_GOS_2_MMEM_SIGP                                            0x1024
#define ACCEL_Y_GOS_3_MMEM_SIGP                                            0x1025
#define ACCEL_Y_GOS_4_MMEM_SIGP                                            0x1026
#define ACCEL_Y_GOS_5_MMEM_SIGP                                            0x1027
#define ACCEL_Y_GOS_6_MMEM_SIGP                                            0x1028
#define ACCEL_Y_GOS_7_MMEM_SIGP                                            0x1029
#define ACCEL_Y_GOS_8_MMEM_SIGP                                            0x102a
#define ACCEL_Y_GOS_9_MMEM_SIGP                                            0x102b
#define ACCEL_Y_GOS_10_MMEM_SIGP                                           0x102c
#define ACCEL_Y_GOS_11_MMEM_SIGP                                           0x102d
#define ACCEL_Y_GOS_12_MMEM_SIGP                                           0x102e
#define ACCEL_Y_GOS_13_MMEM_SIGP                                           0x102f
#define ACCEL_Z_GOS_0_MMEM_SIGP                                            0x103a
#define ACCEL_Z_GOS_1_MMEM_SIGP                                            0x103b
#define ACCEL_Z_GOS_2_MMEM_SIGP                                            0x103c
#define ACCEL_Z_GOS_3_MMEM_SIGP                                            0x103d
#define ACCEL_Z_GOS_4_MMEM_SIGP                                            0x103e
#define ACCEL_Z_GOS_5_MMEM_SIGP                                            0x103f
#define ACCEL_Z_GOS_6_MMEM_SIGP                                            0x1040
#define ACCEL_Z_GOS_7_MMEM_SIGP                                            0x1041
#define ACCEL_Z_GOS_8_MMEM_SIGP                                            0x1042
#define ACCEL_Z_GOS_9_MMEM_SIGP                                            0x1043
#define ACCEL_Z_GOS_10_MMEM_SIGP                                           0x1044
#define ACCEL_Z_GOS_11_MMEM_SIGP                                           0x1045
#define ACCEL_Z_GOS_12_MMEM_SIGP                                           0x1046
#define ACCEL_Z_GOS_13_MMEM_SIGP                                           0x1047
#define GYRO_X_GOS_0_MMEM_SIGP                                             0x1056
#define GYRO_X_GOS_1_MMEM_SIGP                                             0x1057
#define GYRO_X_GOS_2_MMEM_SIGP                                             0x1058
#define GYRO_X_GOS_3_MMEM_SIGP                                             0x1059
#define GYRO_X_GOS_4_MMEM_SIGP                                             0x105a
#define GYRO_X_GOS_5_MMEM_SIGP                                             0x105b
#define GYRO_X_GOS_6_MMEM_SIGP                                             0x105c
#define GYRO_X_GOS_7_MMEM_SIGP                                             0x105d
#define GYRO_X_GOS_8_MMEM_SIGP                                             0x105e
#define GYRO_X_GOS_9_MMEM_SIGP                                             0x105f
#define GYRO_X_GOS_10_MMEM_SIGP                                            0x1060
#define GYRO_X_GOS_11_MMEM_SIGP                                            0x1061
#define GYRO_X_GOS_12_MMEM_SIGP                                            0x1062
#define GYRO_X_GOS_13_MMEM_SIGP                                            0x1063
#define GYRO_X_GOS_14_MMEM_SIGP                                            0x1064
#define GYRO_X_GOS_15_MMEM_SIGP                                            0x1065
#define GYRO_Y_GOS_0_MMEM_SIGP                                             0x1074
#define GYRO_Y_GOS_1_MMEM_SIGP                                             0x1075
#define GYRO_Y_GOS_2_MMEM_SIGP                                             0x1076
#define GYRO_Y_GOS_3_MMEM_SIGP                                             0x1077
#define GYRO_Y_GOS_4_MMEM_SIGP                                             0x1078
#define GYRO_Y_GOS_5_MMEM_SIGP                                             0x1079
#define GYRO_Y_GOS_6_MMEM_SIGP                                             0x107a
#define GYRO_Y_GOS_7_MMEM_SIGP                                             0x107b
#define GYRO_Y_GOS_8_MMEM_SIGP                                             0x107c
#define GYRO_Y_GOS_9_MMEM_SIGP                                             0x107d
#define GYRO_Y_GOS_10_MMEM_SIGP                                            0x107e
#define GYRO_Y_GOS_11_MMEM_SIGP                                            0x107f
#define GYRO_Y_GOS_12_MMEM_SIGP                                            0x1080
#define GYRO_Y_GOS_13_MMEM_SIGP                                            0x1081
#define GYRO_Y_GOS_14_MMEM_SIGP                                            0x1082
#define GYRO_Y_GOS_15_MMEM_SIGP                                            0x1083
#define GYRO_Z_GOS_0_MMEM_SIGP                                             0x1092
#define GYRO_Z_GOS_1_MMEM_SIGP                                             0x1093
#define GYRO_Z_GOS_2_MMEM_SIGP                                             0x1094
#define GYRO_Z_GOS_3_MMEM_SIGP                                             0x1095
#define GYRO_Z_GOS_4_MMEM_SIGP                                             0x1096
#define GYRO_Z_GOS_5_MMEM_SIGP                                             0x1097
#define GYRO_Z_GOS_6_MMEM_SIGP                                             0x1098
#define GYRO_Z_GOS_7_MMEM_SIGP                                             0x1099
#define GYRO_Z_GOS_8_MMEM_SIGP                                             0x109a
#define GYRO_Z_GOS_9_MMEM_SIGP                                             0x109b
#define GYRO_Z_GOS_10_MMEM_SIGP                                            0x109c
#define GYRO_Z_GOS_11_MMEM_SIGP                                            0x109d
#define GYRO_Z_GOS_12_MMEM_SIGP                                            0x109e
#define GYRO_Z_GOS_13_MMEM_SIGP                                            0x109f
#define GYRO_Z_GOS_14_MMEM_SIGP                                            0x10a0
#define GYRO_Z_GOS_15_MMEM_SIGP                                            0x10a1
#define ACCEL_CONFIG_STATIC0_MMEM_SIGP                                     0x10c0
#define ACCEL_CONFIG_STATIC1_MMEM_SIGP                                     0x10c1
#define GYRO_CONFIG_STATIC0_MMEM_SIGP                                      0x10e0
#define GYRO_CONFIG_STATIC1_MMEM_SIGP                                      0x10e1
#define GYRO_CONFIG_STATIC2_MMEM_SIGP                                      0x10e2
#define GYRO_CONFIG_STATIC3_MMEM_SIGP                                      0x10e3
#define GYRO_CONFIG_STATIC4_MMEM_SIGP                                      0x10e4
#define GYRO_CONFIG_STATIC5_MMEM_SIGP                                      0x10e5
#define GYRO_CONFIG_STATIC6_MMEM_SIGP                                      0x10e6
#define GYRO_CONFIG_STATIC7_MMEM_SIGP                                      0x10e7
#define GYRO_CONFIG_STATIC8_MMEM_SIGP                                      0x10e8
#define GYRO_CONFIG_STATIC9_MMEM_SIGP                                      0x10ea
#define GYRO_CONFIG_STATIC10_MMEM_SIGP                                     0x10ec

/* MREG_TOP1 */
#define TMST_CONFIG1_MREG_TOP1                                             0x00
#define FIFO_CONFIG5_MREG_TOP1                                             0x01
#define FIFO_CONFIG6_MREG_TOP1                                             0x02
#define FSYNC_CONFIG_MREG_TOP1                                             0x03
#define INT_CONFIG0_MREG_TOP1                                              0x04
#define INT_CONFIG1_MREG_TOP1                                              0x05
#define SENSOR_CONFIG3_MREG_TOP1                                           0x06
#define AFSR_CONFIG0_MREG_TOP1                                             0x07
#define AFSR_CONFIG1_MREG_TOP1                                             0x08
#define SPARE0_TRIM_MREG_TOP1                                              0x09
#define SPARE1_TRIM_MREG_TOP1                                              0x0a
#define SPARE2_TRIM_MREG_TOP1                                              0x0b
#define SPARE3_TRIM_MREG_TOP1                                              0x0c
#define TBC_RCOSC_MREG_TOP1                                                0x0d
#define TBC_PLL_MREG_TOP1                                                  0x0e
#define ZA_SENSITIIVY_MREG_TOP1                                            0x0f
#define GXSENSERELP_MREG_TOP1                                              0x10
#define GYSENSERELP_MREG_TOP1                                              0x11
#define GZSENSERELP_MREG_TOP1                                              0x12
#define ST_CONFIG_MREG_TOP1                                                0x13
#define SELFTEST_MREG_TOP1                                                 0x14
#define INTF_CONFIG4_MREG_TOP1                                             0x15
#define PADS_CONFIG1_MREG_TOP1                                             0x16
#define PADS_CONFIG3_MREG_TOP1                                             0x17
#define PADS_CONFIG4_MREG_TOP1                                             0x18
#define PADS_CONFIG5_MREG_TOP1                                             0x19
#define PADS_CONFIG6_MREG_TOP1                                             0x1a
#define PADS_CONFIG7_MREG_TOP1                                             0x1b
#define TEMP_CONFIG1_MREG_TOP1                                             0x1c
#define TEMP_CONFIG2_MREG_TOP1                                             0x1d
#define TEMP_CONFIG3_MREG_TOP1                                             0x1e
#define INTF_CONFIG6_MREG_TOP1                                             0x23
#define INTF_CONFIG11_MREG_TOP1                                            0x24
#define INTF_CONFIG10_MREG_TOP1                                            0x25
#define INTF_COMM_ERR_MREG_TOP1                                            0x26
#define INTF_CONFIG5_MREG_TOP1                                             0x27
#define INTF_CONFIG7_MREG_TOP1                                             0x28
#define INTF_CONFIG8_MREG_TOP1                                             0x29
#define INTF_CONFIG9_MREG_TOP1                                             0x2a
#define OTP_CONFIG_MREG_TOP1                                               0x2b
#define DMP_CONFIG1_MREG_TOP1                                              0x2c
#define DMP_CONFIG2_MREG_TOP1                                              0x2d
#define DMP_RESERVED_MREG_TOP1                                             0x2e
#define INT_SOURCE6_MREG_TOP1                                              0x2f
#define INT_SOURCE7_MREG_TOP1                                              0x30
#define INT_SOURCE8_MREG_TOP1                                              0x31
#define INT_SOURCE9_MREG_TOP1                                              0x32
#define INT_SOURCE10_MREG_TOP1                                             0x33
#define MISC_3_MREG_TOP1                                                   0x34
#define MISC_4_MREG_TOP1                                                   0x35
#define TEST_REG0_MREG_TOP1                                                0x36
#define TEST_REG2_MREG_TOP1                                                0x37
#define GYRO_PWR_CFG0_MREG_TOP1                                            0x38
#define ACCEL_CP_CFG0_MREG_TOP1                                            0x39
#define CP_25V_CFG0_MREG_TOP1                                              0x3a
#define PLL_LP_CFG1_MREG_TOP1                                              0x3b
#define AMP_GSXYZ_CFG0_MREG_TOP1                                           0x3c
#define DMD_GCT_CFG0_MREG_TOP1                                             0x3d
#define TMP_ISD_CFG0_MREG_TOP1                                             0x3e
#define DIG_CLK_CFG0_MREG_TOP1                                             0x3f
#define PSEQ_STATUS_MREG_TOP1                                              0x40
#define MB_CORE_STATUS0_MREG_TOP1                                          0x41
#define MB_CORE_STATUS1_MREG_TOP1                                          0x42
#define DRV_GYR_STATUS0_MREG_TOP1                                          0x43
#define APEX_CONFIG2_MREG_TOP1                                             0x44
#define APEX_CONFIG3_MREG_TOP1                                             0x45
#define APEX_CONFIG4_MREG_TOP1                                             0x46
#define APEX_CONFIG5_MREG_TOP1                                             0x47
#define APEX_CONFIG9_MREG_TOP1                                             0x48
#define APEX_CONFIG10_MREG_TOP1                                            0x49
#define APEX_CONFIG11_MREG_TOP1                                            0x4a
#define ACCEL_WOM_X_THR_MREG_TOP1                                          0x4b
#define ACCEL_WOM_Y_THR_MREG_TOP1                                          0x4c
#define ACCEL_WOM_Z_THR_MREG_TOP1                                          0x4d
#define GOS_USER0_MREG_TOP1                                                0x4e
#define GOS_USER1_MREG_TOP1                                                0x4f
#define GOS_USER2_MREG_TOP1                                                0x50
#define GOS_USER3_MREG_TOP1                                                0x51
#define GOS_USER4_MREG_TOP1                                                0x52
#define GOS_USER5_MREG_TOP1                                                0x53
#define GOS_USER6_MREG_TOP1                                                0x54
#define GOS_USER7_MREG_TOP1                                                0x55
#define GOS_USER8_MREG_TOP1                                                0x56
#define SIGP_CFG0_MREG_TOP1                                                0x57
#define SIGP_CFG1_MREG_TOP1                                                0x58
#define SIGP_CFG2_MREG_TOP1                                                0x59
#define GYRO_TRIM1_MREG_TOP1                                               0x5a
#define WUOSC_TRIM_MREG_TOP1                                               0x5b
#define ANA_LAT_TRIM_MREG_TOP1                                             0x5c
#define MISC_2_MREG_TOP1                                                   0x5d
#define TESTMUX_SEL_MREG_TOP1                                              0x5e
#define ADI_0_MREG_TOP1                                                    0x5f
#define ADI_1_MREG_TOP1                                                    0x60
#define ADI_2_MREG_TOP1                                                    0x61
#define ADI_3_MREG_TOP1                                                    0x62
#define ST_STATUS1_MREG_TOP1                                               0x63
#define ST_STATUS2_MREG_TOP1                                               0x64
#define OTP_BNK4_MREG_TOP1                                                 0x65
#define PSEQ_SPARE_TRIM_MREG_TOP1                                          0x66
#define APEX_CONFIG12_MREG_TOP1                                            0x67
#define APEX_CONFIG13_MREG_TOP1                                            0x68

/* MMEM_TOP */
#define XA_ST_DATA_MMEM_TOP                                                0x5000
#define YA_ST_DATA_MMEM_TOP                                                0x5001
#define ZA_ST_DATA_MMEM_TOP                                                0x5002
#define XG_ST_DATA_MMEM_TOP                                                0x5003
#define YG_ST_DATA_MMEM_TOP                                                0x5004
#define ZG_ST_DATA_MMEM_TOP                                                0x5005

/* MREG_OTP */
#define OTP_CTRL3_MREG_OTP                                                 0x2800
#define OTP_CTRL4_MREG_OTP                                                 0x2801
#define OTP_CTRL5_MREG_OTP                                                 0x2802
#define OTP_CTRL6_MREG_OTP                                                 0x2803
#define OTP_CTRL1_MREG_OTP                                                 0x2804
#define OTP_CTRL2_MREG_OTP                                                 0x2805
#define OTP_CTRL7_MREG_OTP                                                 0x2806

/* MREG_FPGA */
#define MSTR_SPI_CTRL_MREG_FPGA                                            0x8003
#define MSTR_SPI_ADDR_MREG_FPGA                                            0x8004
#define MSTR_SPI_WR_DATA_MREG_FPGA                                         0x8005
#define MSTR_SPI_RD_DATA_MREG_FPGA                                         0x8006
#define MSTR_SPI_STATUS_MREG_FPGA                                          0x8007
#define SENSOR_DATA_CTRL_MREG_FPGA                                         0x8008
#define FPGA_ID_MREG_FPGA                                                  0x8009
#define FPGA_CONFIG_MREG_FPGA                                              0x800a
#define REVISION1_MREG_FPGA                                                0x800b
#define REVISION2_MREG_FPGA                                                0x800c
#define ACCEL_X_FRE_MREG_FPGA                                              0x800d
#define ACCEL_X_AMP_MREG_FPGA                                              0x800e
#define ACCEL_X_OFS_MREG_FPGA                                              0x800f
#define ACCEL_X_PHA_MREG_FPGA                                              0x8010
#define ACCEL_X_Y_AEX_MREG_FPGA                                            0x8011
#define ACCEL_Y_FRE_MREG_FPGA                                              0x8012
#define ACCEL_Y_AMP_MREG_FPGA                                              0x8013
#define ACCEL_Y_OFS_MREG_FPGA                                              0x8014
#define ACCEL_Y_PHA_MREG_FPGA                                              0x8015
#define ACCEL_Z_FRE_MREG_FPGA                                              0x8016
#define ACCEL_Z_AMP_MREG_FPGA                                              0x8017
#define ACCEL_Z_OFS_MREG_FPGA                                              0x8018
#define ACCEL_Z_PHA_MREG_FPGA                                              0x8019
#define ACCEL_Z_GYRO_X_AEX_MREG_FPGA                                       0x801a
#define GYRO_X_FRE_MREG_FPGA                                               0x801b
#define GYRO_X_AMP_MREG_FPGA                                               0x801c
#define GYRO_X_OFS_MREG_FPGA                                               0x801d
#define GYRO_X_PHA_MREG_FPGA                                               0x801e
#define GYRO_Y_FRE_MREG_FPGA                                               0x801f
#define GYRO_Y_AMP_MREG_FPGA                                               0x8020
#define GYRO_Y_OFS_MREG_FPGA                                               0x8021
#define GYRO_Y_PHA_MREG_FPGA                                               0x8022
#define GYRO_Y_GYRO_Z_AEX_MREG_FPGA                                        0x8023
#define GYRO_Z_FRE_MREG_FPGA                                               0x8024
#define GYRO_Z_AMP_MREG_FPGA                                               0x8025
#define GYRO_Z_OFS_MREG_FPGA                                               0x8026
#define GYRO_Z_PHA_MREG_FPGA                                               0x8027
#define ACCEL_GRYO_CLKDIV_MREG_FPGA                                        0x8028
#define FPGA_CTRL_MREG_FPGA                                                0x8029
#define FPGA_REG0_MREG_FPGA                                                0x802a
#define FPGA_REG1_MREG_FPGA                                                0x802b
#define FPGA_REG2_MREG_FPGA                                                0x802c
#define FPGA_REG3_MREG_FPGA                                                0x802d
#define FPGA_REG4_MREG_FPGA                                                0x802e
#define FPGA_REG5_MREG_FPGA                                                0x802f

/* ROM */


/* ---------------------------------------------------------------------------
 * register BANK0
 * ---------------------------------------------------------------------------*/

/*
 * MISC_1
 * Register Name : MISC_1
 */

/*
 * auto_inc_dis 
 * This bit controls whether slave will auto increment the address used for accessing registers in mclk domain (or the MREGs).
 * 
 * 1: slave does not auto increment the address. For each read or write access to MREGs, host need to specify a new address by programming maddr_r or maddr_w register. Or otherwise, the previous value in maddr_r or maddr_w is used for MREG accessing. 
 * 
 * 0: After host completes a write operation to MREGs, slave auto increments the internal address pointing to next MREG location. After host completes a read operation to MREGs, slave auto increments the internal address pointing to next MREG location. Slave then performs a read-prefetch based on the auto-incremented address.
 */
#define MISC_1_AUTO_INC_DIS_POS      0x04
#define MISC_1_AUTO_INC_DIS_MASK     (0x01 << MISC_1_AUTO_INC_DIS_POS)

/*
 * en_gyro_pll_refclk 
 * Bit to force the RSOSC on (So RCOSC can 
 * Be divided and used as reference for the PLL)
 */
#define MISC_1_EN_GYRO_PLL_REFCLK_POS      0x01
#define MISC_1_EN_GYRO_PLL_REFCLK_MASK     (0x01 << MISC_1_EN_GYRO_PLL_REFCLK_POS)

/*
 * otp_done 
 * 1 to indicate OTP_copy operation is done.
 */
#define MISC_1_OTP_DONE_POS      0x00
#define MISC_1_OTP_DONE_MASK     0x01



/*
 * CHIP_CONFIG_REG
 * Register Name : CHIP_CONFIG_REG
 */

/*
 * cmos_trim_complete 
 * 1 to indicate CMOS related trim is done.
 */
#define CHIP_CONFIG_REG_CMOS_TRIM_COMPLETE_POS      0x03
#define CHIP_CONFIG_REG_CMOS_TRIM_COMPLETE_MASK     (0x01 << CHIP_CONFIG_REG_CMOS_TRIM_COMPLETE_POS)

/*
 * password_en 
 * External document:  
 *    Use "Reserved", instead of password_en. This bit must stay at value of 0. If this bit is set to 1 by mistake, chip reset is required.
 * 
 * Internal document: 
 *    Enables Password protection for the CONFIG registers.
 * If password_en = 0, chip is not locked: User can read password_en, and value of 0 is returned. User can write 1 to password_en to lock chip.
 * 
 * If reg_password_en = 1 and if chip is locked: User can read reg_password_en, and value of 1 is returned to indicate chip is still in lock to indicate chip is still in lock. User can't write to reg_password_en.
 * 
 * If reg_password_en = 1 and if chip is unlocked by password: User can read reg_password_en, and value of 0 is return to indicate chip is unlocked. User can write 1 to reg_password_en to revoke password and relock the chip.
 */
#define CHIP_CONFIG_REG_PASSWORD_EN_POS      0x01
#define CHIP_CONFIG_REG_PASSWORD_EN_MASK     (0x01 << CHIP_CONFIG_REG_PASSWORD_EN_POS)

/*
 * ODRGRID0
 * Register Name : ODRGRID0
 */

/*
 * odrgrid 
 * Shows the grid alignment for the ODR samples produced by sensors. The following bit(s) will be set to 1 when the corresponding ODR samples are produced
 * bit15 .. bit 11 -:  Always high
 * bit10 -:  1.6 kHz
 * bit9 -:  800 Hz
 * bit8 -:  400 Hz
 * bit7 -:  200 Hz
 * bit6 -:  100 Hz 
 * bit5 -:  50 Hz
 * bit4 -:  25 Hz
 * bit3 -:  12.5 Hz
 * bit2 -:  6.25 Hz
 * bit1 -:  3.125 Hz
 * bit0 -:  1.5625 Hz
 */
#define ODRGRID0_ODRGRID_POS      0x00
#define ODRGRID0_ODRGRID_MASK     0xff



/*
 * ODRGRID1
 * Register Name : ODRGRID1
 */

/*
 * odrgrid 
 * Shows the grid alignment for the ODR samples produced by sensors. The following bit(s) will be set to 1 when the corresponding ODR samples are produced
 * bit15 .. bit 11 -:  Always high
 * bit10 -:  1.6 kHz
 * bit9 -:  800 Hz
 * bit8 -:  400 Hz
 * bit7 -:  200 Hz
 * bit6 -:  100 Hz 
 * bit5 -:  50 Hz
 * bit4 -:  25 Hz
 * bit3 -:  12.5 Hz
 * bit2 -:  6.25 Hz
 * bit1 -:  3.125 Hz
 * bit0 -:  1.5625 Hz
 */
#define ODRGRID1_ODRGRID_POS      0x00
#define ODRGRID1_ODRGRID_MASK     0xff



/*
 * ODR_LP_STATUS
 * Register Name : ODR_LP_STATUS
 */

/*
 * odr_accel_lp_invalid 
 * 1 to indicate ODR Accel Low power invalid case. 
 * This bit could return a false "1" if read during a power mode/ODR change. Be sure that the mode/configuration is changed before reading it.
 */
#define ODR_LP_STATUS_ODR_ACCEL_LP_INVALID_POS      0x00
#define ODR_LP_STATUS_ODR_ACCEL_LP_INVALID_MASK     0x01

/*
 * odr_accel_wuosc_lp_invalid 
 * 1 to indicate ODR Accel WUOSC Low power invalid case.
 * This bit could return a false "1" if read during a power mode/ODR change. Be sure that the mode/configuration is changed before reading it.
 */
#define ODR_LP_STATUS_ODR_ACCEL_WUOSC_LP_INVALID_POS      0x01
#define ODR_LP_STATUS_ODR_ACCEL_WUOSC_LP_INVALID_MASK     (0x01 << ODR_LP_STATUS_ODR_ACCEL_WUOSC_LP_INVALID_POS)

/*
 * odr_gyro_lp_invalid 
 * 1 to indicate ODR Gyro Low power invalid case.
 * This bit could return a false "1" if read during a power mode/ODR change. Be sure that the mode/configuration is changed before reading it.
 */
#define ODR_LP_STATUS_ODR_GYRO_LP_INVALID_POS      0x02
#define ODR_LP_STATUS_ODR_GYRO_LP_INVALID_MASK     (0x01 << ODR_LP_STATUS_ODR_GYRO_LP_INVALID_POS)



/*
 * PWR_MGMT_0
 * Register Name : PWR_MGMT_0
 */

/*
 * temp_dis 
 * This bit disables the temp sensor.
 */
#define PWR_MGMT_0_TEMP_DIS_POS      0x06
#define PWR_MGMT_0_TEMP_DIS_MASK     (0x01 << PWR_MGMT_0_TEMP_DIS_POS)

/*
 * GYRO_CONFIG1
 * Register Name : GYRO_CONFIG1
 */

/*
 * gyro_ui_avg_ind 
 * LPM number of averaged ADC samples to generate output sample
 * 0 -:  2 averaged samples
 * 1 -:  4 averaged samples
 * 2 -:  8 averaged samples
 * 3 -:  16 averaged samples
 * 4 -:  32 averaged samples
 * 5 -:  64 averaged samples
 * 6 -:  64 averaged samples
 * 7 -:  64 averaged samples
 * 
 * This field cannot be changed when the gyro sensor is in LPM
 */
#define GYRO_CONFIG1_GYRO_UI_AVG_IND_POS      0x04
#define GYRO_CONFIG1_GYRO_UI_AVG_IND_MASK     (0x07 << GYRO_CONFIG1_GYRO_UI_AVG_IND_POS)

/*
 * APEX_CONFIG0
 * Register Name : APEX_CONFIG0
 */

/*
 * dmp_dma_inhibit_accel_data 
 * When this bit is 1'b1' DMP will block accel data to SRAM during APEX operation and DMP will bypass DMA during Self-test operation.
 */
#define APEX_CONFIG0_DMP_DMA_INHIBIT_ACCEL_DATA_POS      0x04
#define APEX_CONFIG0_DMP_DMA_INHIBIT_ACCEL_DATA_MASK     (0x01 << APEX_CONFIG0_DMP_DMA_INHIBIT_ACCEL_DATA_POS)

/*
 * INTF_CONFIG0
 * Register Name : INTF_CONFIG0
 */

/*
 * fifo_sreg_invalid_ind_dis 
 * if INVALID_IND_DIS == 1
 * •        In FIFO: the last Valid and New sample is held and written into the FIFO upon reception of cnt_sreg_update.
 * If no Valid and New sample had been received since the reset, 0x0000 will be written in FIFO
 * •        In Sensor Data Registers: the last Valid and New sample is held
 * If no Valid and New sample had been received since the reset, the register default value is read back (that is 0x8000)
 */
#define INTF_CONFIG0_FIFO_SREG_INVALID_IND_DIS_POS      0x07
#define INTF_CONFIG0_FIFO_SREG_INVALID_IND_DIS_MASK     (0x01 << INTF_CONFIG0_FIFO_SREG_INVALID_IND_DIS_POS)

/*
 * sifs_ap_cfg 
 * 0x: automatic protocol
 * 10: I2C only (1)
 * 11: SPI only (2)
 *  (1)  10 setting will be effectively disabling SPI protocol only in case ap_i2c_only and ap_spi_only are both 0’s (concurrent protocol). In I2C only pad scenarios this setting would be useless, in SPI only pad scenarios it would be harmful (the only available protocol would be killed)
 *   (2)  11 setting will be effectively disabling I2C protocol only in case ap_i2c_only and ap_spi_only are both 0’s (concurrent protocol). In SPI only pad scenarios this setting would be useless, in I2C only pad scenarios it would be harmful (the only available protocol would be killed)
 */
#define INTF_CONFIG0_SIFS_AP_CFG_POS      0x00
#define INTF_CONFIG0_SIFS_AP_CFG_MASK     0x03



/*
 * INTF_CONFIG1
 * Register Name : INTF_CONFIG1
 */

/*
 * gyro_afsr_mode 
 * 00 : AFSR is disabled -System defaults to LFS , auto selection is disabled
 * 01 : AFSR is disabled -System defaults to HFS , auto selection is disabled
 * 1x : AFSR is enabled – System defaults to Dynamic selection
 * NOTE: this register is only active if feature is enabled --:  see afsr_feature_disable
 */
#define INTF_CONFIG1_GYRO_AFSR_MODE_POS      0x05
#define INTF_CONFIG1_GYRO_AFSR_MODE_MASK     (0x03 << INTF_CONFIG1_GYRO_AFSR_MODE_POS)

/*
 * SCAN1
 * Register Name : SCAN1
 */

/*
 * scan_por_disable_d2a 
 * nan
 */
#define SCAN1_SCAN_POR_DISABLE_D2A_POS      0x05
#define SCAN1_SCAN_POR_DISABLE_D2A_MASK     (0x01 << SCAN1_SCAN_POR_DISABLE_D2A_POS)

/*
 * scan_dreg_switch_on_d2a 
 * nan
 */
#define SCAN1_SCAN_DREG_SWITCH_ON_D2A_POS      0x04
#define SCAN1_SCAN_DREG_SWITCH_ON_D2A_MASK     (0x01 << SCAN1_SCAN_DREG_SWITCH_ON_D2A_POS)

/*
 * dft_mode 
 * This bit will statically selects whether the memory/OTP accesses will be done; i.e. when set to ‘1’ the internal memory accesses will be enabled (and the FIFO won’t work, like in bypass mode); this setting will be used for Secure Authentication, OTP programming/checking and during debug phase. 
 * While when set to ‘0’ the FIFO will work as usual and the access of the internal memory is prevented.
 */
#define SCAN1_DFT_MODE_POS      0x00
#define SCAN1_DFT_MODE_MASK     0x0f



/*
 * CKG_STATUS
 * Register Name : CKG_STATUS
 */

/*
 * ckg_rcosc_in_use 
 * Read back from CKG (debug feature)
 */
#define CKG_STATUS_CKG_RCOSC_IN_USE_POS      0x03
#define CKG_STATUS_CKG_RCOSC_IN_USE_MASK     (0x01 << CKG_STATUS_CKG_RCOSC_IN_USE_POS)

/*
 * ckg_pll_in_use 
 * Read back from CKG (debug feature)
 */
#define CKG_STATUS_CKG_PLL_IN_USE_POS      0x02
#define CKG_STATUS_CKG_PLL_IN_USE_MASK     (0x01 << CKG_STATUS_CKG_PLL_IN_USE_POS)

/*
 * ckg_ext_in_use 
 * Read back from CKG (debug feature)
 */
#define CKG_STATUS_CKG_EXT_IN_USE_POS      0x01
#define CKG_STATUS_CKG_EXT_IN_USE_MASK     (0x01 << CKG_STATUS_CKG_EXT_IN_USE_POS)



/*
 * GYR_BIAS_CFG1
 * Register Name : GYR_BIAS_CFG1
 */

/*
 * pd_gyro_bias_master_b 
 * Gyro Bias master powerdown override. 
 * 0: pd_gyro_bias_master_b_d2a dynamic signal (output of digital top) should be forced to 0, 
 * 1: pd_gyro_bias_master_b_d2a should follow the specified dynamic behavior.
 */
#define GYR_BIAS_CFG1_PD_GYRO_BIAS_MASTER_B_POS      0x00
#define GYR_BIAS_CFG1_PD_GYRO_BIAS_MASTER_B_MASK     0x01



/*
 * DIG_CLK_CFG1
 * Register Name : DIG_CLK_CFG1
 */

/*
 * dis_clk_dig_4m 
 * Disables the 4MHz clock muxed by ckg_top, for silicon power measurements.
 */
#define DIG_CLK_CFG1_DIS_CLK_DIG_4M_POS      0x00
#define DIG_CLK_CFG1_DIS_CLK_DIG_4M_MASK     0x01



/*
 * AMP_GDC2V_CFG0
 * Register Name : AMP_GDC2V_CFG0
 */

/*
 * pd_gyro_dc2v_b 
 * Gyro drive power-down override. 
 * 0: pd_gyro_dc2v_b_d2a dynamic signal (output of digital top) should be forced to 0, 
 * 1: pd_gyro_dc2v_b_d2a should follow the specified dynamic behavior.
 */
#define AMP_GDC2V_CFG0_PD_GYRO_DC2V_B_POS      0x01
#define AMP_GDC2V_CFG0_PD_GYRO_DC2V_B_MASK     (0x01 << AMP_GDC2V_CFG0_PD_GYRO_DC2V_B_POS)

/*
 * rst_gyro_dc2v_b 
 * Gyro drive reset override. 
 * 0: rst_gyro_dc2v_b_d2a dynamic signal (output of digital top) should be forced to 0,
 * 1: rst_gyro_dc2v_b_d2a should follow the specified dynamic behavior.
 */
#define AMP_GDC2V_CFG0_RST_GYRO_DC2V_B_POS      0x00
#define AMP_GDC2V_CFG0_RST_GYRO_DC2V_B_MASK     0x01



/*
 * DRV_GYR_CFG4
 * Register Name : DRV_GYR_CFG4
 */

/*
 * rst_gyro_drv_b 
 * Gyro drive reset override; 
 * 0: rst_gyro_drv_b_d2a dynamic signal (output of digital top) should be forced to 0,
 * 1: rst_gyro_drv_b_d2a should follow the specified dynamic behavior.
 */
#define DRV_GYR_CFG4_RST_GYRO_DRV_B_POS      0x01
#define DRV_GYR_CFG4_RST_GYRO_DRV_B_MASK     (0x01 << DRV_GYR_CFG4_RST_GYRO_DRV_B_POS)

/*
 * pd_gyro_drv_b 
 * Gyro drive power down override; 
 * 0: pd_gyro_drv_b_d2a dynamic signal (output of digital top) should be forced to 0, 
 * 1: pd_gyro_drv_b_d2a should follow the specified dynamic behavior.
 */
#define DRV_GYR_CFG4_PD_GYRO_DRV_B_POS      0x00
#define DRV_GYR_CFG4_PD_GYRO_DRV_B_MASK     0x01



/*
 * PLL_LP_CFG0
 * Register Name : PLL_LP_CFG0
 */

/*
 * pd_gyro_pll_b 
 * PLL power-down override. 
 * 0: pd_gyro_pll_b_d2a dynamic signal (output of digital top) should be forced to 0, 
 * 1: pd_gyro_pll_b_d2a should follow the specified dynamic behavior.
 */
#define PLL_LP_CFG0_PD_GYRO_PLL_B_POS      0x01
#define PLL_LP_CFG0_PD_GYRO_PLL_B_MASK     (0x01 << PLL_LP_CFG0_PD_GYRO_PLL_B_POS)

/*
 * rst_gyro_pll_b 
 * PLL reset override. 
 * 0: rst_gyro_pll_b_d2a dynamic signal (output of digital top) should be forced to 0,
 * 1: rst_gyro_pll_b_d2a should follow the specified dynamic behavior.
 */
#define PLL_LP_CFG0_RST_GYRO_PLL_B_POS      0x00
#define PLL_LP_CFG0_RST_GYRO_PLL_B_MASK     0x01



/*
 * INTF_CONFIG2
 * Register Name : INTF_CONFIG2
 */

/*
 * pads_ap_sdo_od_d2a 
 * nan
 */
#define INTF_CONFIG2_PADS_AP_SDO_OD_D2A_POS      0x03
#define INTF_CONFIG2_PADS_AP_SDO_OD_D2A_MASK     (0x01 << INTF_CONFIG2_PADS_AP_SDO_OD_D2A_POS)

/*
 * pads_ap_sdi_od 
 * nan
 */
#define INTF_CONFIG2_PADS_AP_SDI_OD_POS      0x02
#define INTF_CONFIG2_PADS_AP_SDI_OD_MASK     (0x01 << INTF_CONFIG2_PADS_AP_SDI_OD_POS)

/*
 * pads_ap_sclk_od 
 * nan
 */
#define INTF_CONFIG2_PADS_AP_SCLK_OD_POS      0x01
#define INTF_CONFIG2_PADS_AP_SCLK_OD_MASK     (0x01 << INTF_CONFIG2_PADS_AP_SCLK_OD_POS)

/*
 * pads_ap_cs_od_d2a 
 * nan
 */
#define INTF_CONFIG2_PADS_AP_CS_OD_D2A_POS      0x00
#define INTF_CONFIG2_PADS_AP_CS_OD_D2A_MASK     0x01



/*
 * INTF_CONFIG3
 * Register Name : INTF_CONFIG3
 */

/*
 * pads_ap_sdo_from_pad_disable_d2a 
 * Receiver Enable, Low Assertion: 1= RX Path Disabled, 0 = RX Path Enabled.
 * Set to 1 when SPI configuration is selected
 */
#define INTF_CONFIG3_PADS_AP_SDO_FROM_PAD_DISABLE_D2A_POS      0x03
#define INTF_CONFIG3_PADS_AP_SDO_FROM_PAD_DISABLE_D2A_MASK     (0x01 << INTF_CONFIG3_PADS_AP_SDO_FROM_PAD_DISABLE_D2A_POS)

/*
 * pads_ap_sdi_from_pad_disable_d2a 
 * nan
 */
#define INTF_CONFIG3_PADS_AP_SDI_FROM_PAD_DISABLE_D2A_POS      0x02
#define INTF_CONFIG3_PADS_AP_SDI_FROM_PAD_DISABLE_D2A_MASK     (0x01 << INTF_CONFIG3_PADS_AP_SDI_FROM_PAD_DISABLE_D2A_POS)

/*
 * pads_ap_sclk_from_pad_disable_d2a 
 * nan
 */
#define INTF_CONFIG3_PADS_AP_SCLK_FROM_PAD_DISABLE_D2A_POS      0x01
#define INTF_CONFIG3_PADS_AP_SCLK_FROM_PAD_DISABLE_D2A_MASK     (0x01 << INTF_CONFIG3_PADS_AP_SCLK_FROM_PAD_DISABLE_D2A_POS)

/*
 * pads_ap_cs_from_pad_disable_d2a 
 * nan
 */
#define INTF_CONFIG3_PADS_AP_CS_FROM_PAD_DISABLE_D2A_POS      0x00
#define INTF_CONFIG3_PADS_AP_CS_FROM_PAD_DISABLE_D2A_MASK     0x01



/*
 * SREG_SPARE1
 * Register Name : SREG_SPARE1
 */

/*
 * sreg_spare1 
 * spare register
 */
#define SREG_SPARE1_SREG_SPARE1_POS      0x00
#define SREG_SPARE1_SREG_SPARE1_MASK     0xff



/*
 * SREG_SPARE2
 * Register Name : SREG_SPARE2
 */

/*
 * sreg_spare2 
 * spare register
 */
#define SREG_SPARE2_SREG_SPARE2_POS      0x00
#define SREG_SPARE2_SREG_SPARE2_MASK     0xff



/*
 * SREG_SPARE3
 * Register Name : SREG_SPARE3
 */

/*
 * sreg_spare3 
 * spare register
 */
#define SREG_SPARE3_SREG_SPARE3_POS      0x00
#define SREG_SPARE3_SREG_SPARE3_MASK     0xff



/*
 * SREG_SPARE4
 * Register Name : SREG_SPARE4
 */

/*
 * sreg_spare4 
 * spare register
 */
#define SREG_SPARE4_SREG_SPARE4_POS      0x00
#define SREG_SPARE4_SREG_SPARE4_MASK     0xff


/* ---------------------------------------------------------------------------
 * register MREG_BAR
 * ---------------------------------------------------------------------------*/

/*
 * TMP_BAR_0_BYTE_0
 * Register Name : TMP_BAR_0_BYTE_0
 */

/*
 * tmp_dvbe_c 
 * coarse dvbe trimming codeword
 */
#define TMP_BAR_0_BYTE_0_TMP_DVBE_C_POS      0x04
#define TMP_BAR_0_BYTE_0_TMP_DVBE_C_MASK     (0x0f << TMP_BAR_0_BYTE_0_TMP_DVBE_C_POS)

/*
 * tmp_vbe_c 
 * coarse vbe trimming codeword
 */
#define TMP_BAR_0_BYTE_0_TMP_VBE_C_POS      0x00
#define TMP_BAR_0_BYTE_0_TMP_VBE_C_MASK     0x0f



/*
 * TMP_BAR_0_BYTE_1
 * Register Name : TMP_BAR_0_BYTE_1
 */

/*
 * pd_tmp_b_ov 
 * power_down_b override bit
 */
#define TMP_BAR_0_BYTE_1_PD_TMP_B_OV_POS      0x07
#define TMP_BAR_0_BYTE_1_PD_TMP_B_OV_MASK     (0x01 << TMP_BAR_0_BYTE_1_PD_TMP_B_OV_POS)

/*
 * pd_tmp_b_digmask 
 * nan
 */
#define TMP_BAR_0_BYTE_1_PD_TMP_B_DIGMASK_POS      0x06
#define TMP_BAR_0_BYTE_1_PD_TMP_B_DIGMASK_MASK     (0x01 << TMP_BAR_0_BYTE_1_PD_TMP_B_DIGMASK_POS)

/*
 * tmp_dvbe_f 
 * fine dvbe trimming codeword
 */
#define TMP_BAR_0_BYTE_1_TMP_DVBE_F_POS      0x00
#define TMP_BAR_0_BYTE_1_TMP_DVBE_F_MASK     0x1f

/*
 * tmp_spare 
 * OTP spare
 */
#define TMP_BAR_0_BYTE_1_TMP_SPARE_POS      0x05
#define TMP_BAR_0_BYTE_1_TMP_SPARE_MASK     (0x01 << TMP_BAR_0_BYTE_1_TMP_SPARE_POS)



/*
 * TMP_BAR_0_BYTE_2
 * Register Name : TMP_BAR_0_BYTE_2
 */

/*
 * tmp_spare 
 * OTP spare
 */
#define TMP_BAR_0_BYTE_2_TMP_SPARE_POS      0x05
#define TMP_BAR_0_BYTE_2_TMP_SPARE_MASK     (0x07 << TMP_BAR_0_BYTE_2_TMP_SPARE_POS)

/*
 * tmp_vbe_f 
 * fine vbe trimming codeword
 */
#define TMP_BAR_0_BYTE_2_TMP_VBE_F_POS      0x00
#define TMP_BAR_0_BYTE_2_TMP_VBE_F_MASK     0x1f



/*
 * TMP_BAR_0_BYTE_3
 * Register Name : TMP_BAR_0_BYTE_3
 */

/*
 * tmp_testmode 
 * nan
 */
#define TMP_BAR_0_BYTE_3_TMP_TESTMODE_POS      0x00
#define TMP_BAR_0_BYTE_3_TMP_TESTMODE_MASK     0xff



/*
 * GYRO_DC2V_BAR_1_BYTE_0
 * Register Name : GYRO_DC2V_BAR_1_BYTE_0
 */

/*
 * gyro_dc2v_gain 
 * dc2v gain trim
 */
#define GYRO_DC2V_BAR_1_BYTE_0_GYRO_DC2V_GAIN_POS      0x00
#define GYRO_DC2V_BAR_1_BYTE_0_GYRO_DC2V_GAIN_MASK     0x0f

/*
 * gyro_dc2v_fet 
 * dc2v giga-ohm fet trim
 */
#define GYRO_DC2V_BAR_1_BYTE_0_GYRO_DC2V_FET_POS      0x04
#define GYRO_DC2V_BAR_1_BYTE_0_GYRO_DC2V_FET_MASK     (0x03 << GYRO_DC2V_BAR_1_BYTE_0_GYRO_DC2V_FET_POS)



/*
 * GYRO_DC2V_BAR_1_BYTE_1
 * Register Name : GYRO_DC2V_BAR_1_BYTE_1
 */

/*
 * gyro_dc2v_ptatblend 
 * dc2v ptatblend trim = 9 produces lowest non-linear phase variation over temp and lowest non-linear phase variation over temp mismatch between DC2V and SC2V
 */
#define GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_PTATBLEND_POS      0x00
#define GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_PTATBLEND_MASK     0x0f

/*
 * gyro_dc2v_rst_time 
 * dc2v ramped rest time trim to remove offset from DC2V output due to incomplete ring down of MEMS at the power ON of DC2V after reset goes from low to high
 */
#define GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_RST_TIME_POS      0x04
#define GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_RST_TIME_MASK     (0x03 << GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_RST_TIME_POS)

/*
 * gyro_dc2v_cont_mode 
 * dc2v continuous mode trim:                                                                                                                                                                                                                                                      0b: DC2V is in switched feedback(no Giga-ohm FET)                                                                                                                                                                                                                                             1b: DC2V is in continuous feedback(there is Giga-ohm FET)
 */
#define GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_CONT_MODE_POS      0x06
#define GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_CONT_MODE_MASK     (0x01 << GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_CONT_MODE_POS)

/*
 * gyro_dc2v_cc 
 * dc2v compensation cap trim for better phase margin:                                                                                                                                                                                                         0b: do not increase Cc                                                                                                                                                                                                                                                                 1b: increase Cc for better phase margin
 */
#define GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_CC_POS      0x07
#define GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_CC_MASK     (0x01 << GYRO_DC2V_BAR_1_BYTE_1_GYRO_DC2V_CC_POS)



/*
 * GYRO_DC2V_BAR_1_BYTE_2
 * Register Name : GYRO_DC2V_BAR_1_BYTE_2
 */

/*
 * gyro_dc2v_drvstr 
 * enable/disable higher dc2v drive strength for test mode:                                                                                                                                                                                                   00b: enable higher dc2v drive strength depedent on testmode<3:0: (any bit of testmode<3:0:  is logic 1)                                                                                                                                                                                 01b: enable higher dc2v drive strength indepedent on testmode<3:0:                                                                                                                                                                              1xb: disable higher dc2v drive strength indepedent on testmode<3:0: 
 */
#define GYRO_DC2V_BAR_1_BYTE_2_GYRO_DC2V_DRVSTR_POS      0x00
#define GYRO_DC2V_BAR_1_BYTE_2_GYRO_DC2V_DRVSTR_MASK     0x03

/*
 * gyro_dc2v_spare 
 * dc2v spare bits
 */
#define GYRO_DC2V_BAR_1_BYTE_2_GYRO_DC2V_SPARE_POS      0x02
#define GYRO_DC2V_BAR_1_BYTE_2_GYRO_DC2V_SPARE_MASK     (0x3f << GYRO_DC2V_BAR_1_BYTE_2_GYRO_DC2V_SPARE_POS)



/*
 * GYRO_DC2V_BAR_1_BYTE_3
 * Register Name : GYRO_DC2V_BAR_1_BYTE_3
 */

/*
 * gyro_dc2v_testmode 
 * dc2v test mode
 */
#define GYRO_DC2V_BAR_1_BYTE_3_GYRO_DC2V_TESTMODE_POS      0x00
#define GYRO_DC2V_BAR_1_BYTE_3_GYRO_DC2V_TESTMODE_MASK     0xff



/*
 * GYRO_CP_BAR_2_BYTE_0
 * Register Name : GYRO_CP_BAR_2_BYTE_0
 */

/*
 * gyro_cp25v_testmode 
 * Testmode bus to control 7 testmodes.
 */
#define GYRO_CP_BAR_2_BYTE_0_GYRO_CP25V_TESTMODE_POS      0x00
#define GYRO_CP_BAR_2_BYTE_0_GYRO_CP25V_TESTMODE_MASK     0xff



/*
 * GYRO_CP_BAR_2_BYTE_1
 * Register Name : GYRO_CP_BAR_2_BYTE_1
 */

/*
 * gyro_cp25v_cfg_spare 
 * Spare CFG bits.
 */
#define GYRO_CP_BAR_2_BYTE_1_GYRO_CP25V_CFG_SPARE_POS      0x00
#define GYRO_CP_BAR_2_BYTE_1_GYRO_CP25V_CFG_SPARE_MASK     0xff



/*
 * GYRO_CP_BAR_2_BYTE_2
 * Register Name : GYRO_CP_BAR_2_BYTE_2
 */

/*
 * gyro_cp25v_cpclkdivrat 
 * CP clock div ratio. '0' - divrat1 (cpclk 4MHz), '1'-divrat2 (cpclk 2MHz)
 */
#define GYRO_CP_BAR_2_BYTE_2_GYRO_CP25V_CPCLKDIVRAT_POS      0x07
#define GYRO_CP_BAR_2_BYTE_2_GYRO_CP25V_CPCLKDIVRAT_MASK     (0x01 << GYRO_CP_BAR_2_BYTE_2_GYRO_CP25V_CPCLKDIVRAT_POS)

/*
 * gyro_cp25v_enchop 
 * Enable chopping.
 */
#define GYRO_CP_BAR_2_BYTE_2_GYRO_CP25V_ENCHOP_POS      0x06
#define GYRO_CP_BAR_2_BYTE_2_GYRO_CP25V_ENCHOP_MASK     (0x01 << GYRO_CP_BAR_2_BYTE_2_GYRO_CP25V_ENCHOP_POS)

/*
 * gyro_cp25v_otp_spare 
 * Spare OTP bits.
 */
#define GYRO_CP_BAR_2_BYTE_2_GYRO_CP25V_OTP_SPARE_POS      0x00
#define GYRO_CP_BAR_2_BYTE_2_GYRO_CP25V_OTP_SPARE_MASK     0x3f



/*
 * GYRO_CP_BAR_2_BYTE_3
 * Register Name : GYRO_CP_BAR_2_BYTE_3
 */

/*
 * gyro_cp25v_r2 
 * Bottom resistor,R2, trimming. Golden trimm.
 */
#define GYRO_CP_BAR_2_BYTE_3_GYRO_CP25V_R2_POS      0x04
#define GYRO_CP_BAR_2_BYTE_3_GYRO_CP25V_R2_MASK     (0x0f << GYRO_CP_BAR_2_BYTE_3_GYRO_CP25V_R2_POS)

/*
 * gyro_cp25v_chopclkdivrat 
 * Chop clk divratio. '0'-divrat24 (166.7kHz), '1'-divrat12 (333.3kHz), '2'-divrat6 (666.7kHz), '3'-divrat48 (83.3kHz)
 */
#define GYRO_CP_BAR_2_BYTE_3_GYRO_CP25V_CHOPCLKDIVRAT_POS      0x02
#define GYRO_CP_BAR_2_BYTE_3_GYRO_CP25V_CHOPCLKDIVRAT_MASK     (0x03 << GYRO_CP_BAR_2_BYTE_3_GYRO_CP25V_CHOPCLKDIVRAT_POS)

/*
 * gyro_cp25v_cprdytimer 
 * cpRDY signal is asserted at 1.5ms based on a counter. We want programmability in future. '0'-1ms, '1'-1.5ms,'2'-2ms, '3'-2.5ms.
 */
#define GYRO_CP_BAR_2_BYTE_3_GYRO_CP25V_CPRDYTIMER_POS      0x00
#define GYRO_CP_BAR_2_BYTE_3_GYRO_CP25V_CPRDYTIMER_MASK     0x03



/*
 * MB_AREG_BAR_3_BYTE_0
 * Register Name : MB_AREG_BAR_3_BYTE_0
 */

/*
 * mb_areg_testmode 
 * Analog remap on ATP of accelerometer avdd regulator
 */
#define MB_AREG_BAR_3_BYTE_0_MB_AREG_TESTMODE_POS      0x00
#define MB_AREG_BAR_3_BYTE_0_MB_AREG_TESTMODE_MASK     0x0f

/*
 * mb_areg_digmask 
 * nan
 */
#define MB_AREG_BAR_3_BYTE_0_MB_AREG_DIGMASK_POS      0x04
#define MB_AREG_BAR_3_BYTE_0_MB_AREG_DIGMASK_MASK     (0x01 << MB_AREG_BAR_3_BYTE_0_MB_AREG_DIGMASK_POS)

/*
 * pd_accel_mb_areg_ovr_b 
 * nan
 */
#define MB_AREG_BAR_3_BYTE_0_PD_ACCEL_MB_AREG_OVR_B_POS      0x05
#define MB_AREG_BAR_3_BYTE_0_PD_ACCEL_MB_AREG_OVR_B_MASK     (0x01 << MB_AREG_BAR_3_BYTE_0_PD_ACCEL_MB_AREG_OVR_B_POS)

/*
 * pd_gyro_mb_areg_ovr_b 
 * nan
 */
#define MB_AREG_BAR_3_BYTE_0_PD_GYRO_MB_AREG_OVR_B_POS      0x06
#define MB_AREG_BAR_3_BYTE_0_PD_GYRO_MB_AREG_OVR_B_MASK     (0x01 << MB_AREG_BAR_3_BYTE_0_PD_GYRO_MB_AREG_OVR_B_POS)

/*
 * pd_gyrocp_mb_areg_ovr_b 
 * nan
 */
#define MB_AREG_BAR_3_BYTE_0_PD_GYROCP_MB_AREG_OVR_B_POS      0x07
#define MB_AREG_BAR_3_BYTE_0_PD_GYROCP_MB_AREG_OVR_B_MASK     (0x01 << MB_AREG_BAR_3_BYTE_0_PD_GYROCP_MB_AREG_OVR_B_POS)



/*
 * MB_AREG_BAR_4_BYTE_0
 * Register Name : MB_AREG_BAR_4_BYTE_0
 */

/*
 * mb_areg_accel 
 * Trim bus for accelerometer analog regulator
 */
#define MB_AREG_BAR_4_BYTE_0_MB_AREG_ACCEL_POS      0x00
#define MB_AREG_BAR_4_BYTE_0_MB_AREG_ACCEL_MASK     0x07

/*
 * mb_areg_gyro 
 * Trim bus for gyroscope analog regulator
 */
#define MB_AREG_BAR_4_BYTE_0_MB_AREG_GYRO_POS      0x03
#define MB_AREG_BAR_4_BYTE_0_MB_AREG_GYRO_MASK     (0x07 << MB_AREG_BAR_4_BYTE_0_MB_AREG_GYRO_POS)



/*
 * MB_AREG_BAR_4_BYTE_1
 * Register Name : MB_AREG_BAR_4_BYTE_1
 */

/*
 * mb_areg_gyrocp 
 * Trim bus for gyroscope chargepump analog regulator
 */
#define MB_AREG_BAR_4_BYTE_1_MB_AREG_GYROCP_POS      0x00
#define MB_AREG_BAR_4_BYTE_1_MB_AREG_GYROCP_MASK     0x07



/*
 * MB_CORE_BAR_5_BYTE_0
 * Register Name : MB_CORE_BAR_5_BYTE_0
 */

/*
 * mb_core_testmode 
 * Testmode bus to control 13 testmodes.
 */
#define MB_CORE_BAR_5_BYTE_0_MB_CORE_TESTMODE_POS      0x00
#define MB_CORE_BAR_5_BYTE_0_MB_CORE_TESTMODE_MASK     0xff



/*
 * MB_CORE_BAR_5_BYTE_1
 * Register Name : MB_CORE_BAR_5_BYTE_1
 */

/*
 * mb_core_spare2 
 * Spare OTP bits.
 */
#define MB_CORE_BAR_5_BYTE_1_MB_CORE_SPARE2_POS      0x05
#define MB_CORE_BAR_5_BYTE_1_MB_CORE_SPARE2_MASK     (0x07 << MB_CORE_BAR_5_BYTE_1_MB_CORE_SPARE2_POS)

/*
 * mb_core_bg_iptat 
 * Brokaw PTAT current trim
 */
#define MB_CORE_BAR_5_BYTE_1_MB_CORE_BG_IPTAT_POS      0x00
#define MB_CORE_BAR_5_BYTE_1_MB_CORE_BG_IPTAT_MASK     0x1f



/*
 * MB_CORE_BAR_5_BYTE_2
 * Register Name : MB_CORE_BAR_5_BYTE_2
 */

/*
 * mb_core_bg_curcorr 
 * Brokaw Curvature Correction
 */
#define MB_CORE_BAR_5_BYTE_2_MB_CORE_BG_CURCORR_POS      0x04
#define MB_CORE_BAR_5_BYTE_2_MB_CORE_BG_CURCORR_MASK     (0x0f << MB_CORE_BAR_5_BYTE_2_MB_CORE_BG_CURCORR_POS)

/*
 * mb_core_spare3 
 * Spare OTP bits.
 */
#define MB_CORE_BAR_5_BYTE_2_MB_CORE_SPARE3_POS      0x01
#define MB_CORE_BAR_5_BYTE_2_MB_CORE_SPARE3_MASK     (0x07 << MB_CORE_BAR_5_BYTE_2_MB_CORE_SPARE3_POS)



/*
 * MB_CORE_BAR_5_BYTE_3
 * Register Name : MB_CORE_BAR_5_BYTE_3
 */

/*
 * mb_core_bg_ptat 
 * Brokaw PTAT trim
 */
#define MB_CORE_BAR_5_BYTE_3_MB_CORE_BG_PTAT_POS      0x00
#define MB_CORE_BAR_5_BYTE_3_MB_CORE_BG_PTAT_MASK     0xff



/*
 * MB_CORE_BAR_6_BYTE_0
 * Register Name : MB_CORE_BAR_6_BYTE_0
 */

/*
 * mbcore_rctrim_cap_sel 
 * Capacitor type selection of MB_CORE RC-trim
 */
#define MB_CORE_BAR_6_BYTE_0_MBCORE_RCTRIM_CAP_SEL_POS      0x04
#define MB_CORE_BAR_6_BYTE_0_MBCORE_RCTRIM_CAP_SEL_MASK     (0x01 << MB_CORE_BAR_6_BYTE_0_MBCORE_RCTRIM_CAP_SEL_POS)

/*
 * mbcore_rctrim_mode 
 * Mode selection of MB_CORE RC-trim
 */
#define MB_CORE_BAR_6_BYTE_0_MBCORE_RCTRIM_MODE_POS      0x03
#define MB_CORE_BAR_6_BYTE_0_MBCORE_RCTRIM_MODE_MASK     (0x01 << MB_CORE_BAR_6_BYTE_0_MBCORE_RCTRIM_MODE_POS)



/*
 * MB_CORE_BAR_6_BYTE_1
 * Register Name : MB_CORE_BAR_6_BYTE_1
 */

/*
 * mb_core_spare1 
 * Spare OTP bits.
 */
#define MB_CORE_BAR_6_BYTE_1_MB_CORE_SPARE1_POS      0x05
#define MB_CORE_BAR_6_BYTE_1_MB_CORE_SPARE1_MASK     (0x07 << MB_CORE_BAR_6_BYTE_1_MB_CORE_SPARE1_POS)

/*
 * mb_core_bg_iptat_id 
 * Brokaw IDEAL PTAT current trim
 */
#define MB_CORE_BAR_6_BYTE_1_MB_CORE_BG_IPTAT_ID_POS      0x00
#define MB_CORE_BAR_6_BYTE_1_MB_CORE_BG_IPTAT_ID_MASK     0x1f



/*
 * MB_CORE_BAR_6_BYTE_2
 * Register Name : MB_CORE_BAR_6_BYTE_2
 */

/*
 * mb_core_spare 
 * Spare non-OTP bits
 */
#define MB_CORE_BAR_6_BYTE_2_MB_CORE_SPARE_POS      0x00
#define MB_CORE_BAR_6_BYTE_2_MB_CORE_SPARE_MASK     0xff



/*
 * MB_CORE_BAR_6_BYTE_3
 * Register Name : MB_CORE_BAR_6_BYTE_3
 */

/*
 * mb_core_bg_ivbgr 
 * Brokaw VBGR current trim
 */
#define MB_CORE_BAR_6_BYTE_3_MB_CORE_BG_IVBGR_POS      0x03
#define MB_CORE_BAR_6_BYTE_3_MB_CORE_BG_IVBGR_MASK     (0x1f << MB_CORE_BAR_6_BYTE_3_MB_CORE_BG_IVBGR_POS)

/*
 * mb_core_dis_curv_corr 
 * Disable Brokaw curvature correction (active high)
 */
#define MB_CORE_BAR_6_BYTE_3_MB_CORE_DIS_CURV_CORR_POS      0x00
#define MB_CORE_BAR_6_BYTE_3_MB_CORE_DIS_CURV_CORR_MASK     0x01



/*
 * MB_CORE_BAR_7_BYTE_0
 * Register Name : MB_CORE_BAR_7_BYTE_0
 */

/*
 * mb_core_testmode 
 * Testmode bus to control 13 testmodes.
 */
#define MB_CORE_BAR_7_BYTE_0_MB_CORE_TESTMODE_POS      0x03
#define MB_CORE_BAR_7_BYTE_0_MB_CORE_TESTMODE_MASK     (0x1f << MB_CORE_BAR_7_BYTE_0_MB_CORE_TESTMODE_POS)



/*
 * MB_CORE_BAR_7_BYTE_1
 * Register Name : MB_CORE_BAR_7_BYTE_1
 */

/*
 * mb_core_vref_cp1p6v_brokaw 
 * CP 1.6-V reference trim
 */
#define MB_CORE_BAR_7_BYTE_1_MB_CORE_VREF_CP1P6V_BROKAW_POS      0x03
#define MB_CORE_BAR_7_BYTE_1_MB_CORE_VREF_CP1P6V_BROKAW_MASK     (0x1f << MB_CORE_BAR_7_BYTE_1_MB_CORE_VREF_CP1P6V_BROKAW_POS)

/*
 * mb_core_avdd 
 * mbcore AREG trim
 */
#define MB_CORE_BAR_7_BYTE_1_MB_CORE_AVDD_POS      0x00
#define MB_CORE_BAR_7_BYTE_1_MB_CORE_AVDD_MASK     0x07



/*
 * MB_CORE_BAR_7_BYTE_2
 * Register Name : MB_CORE_BAR_7_BYTE_2
 */

/*
 * mb_core_vref_cp1p6v_vref_alwayson 
 * nan
 */
#define MB_CORE_BAR_7_BYTE_2_MB_CORE_VREF_CP1P6V_VREF_ALWAYSON_POS      0x03
#define MB_CORE_BAR_7_BYTE_2_MB_CORE_VREF_CP1P6V_VREF_ALWAYSON_MASK     (0x1f << MB_CORE_BAR_7_BYTE_2_MB_CORE_VREF_CP1P6V_VREF_ALWAYSON_POS)

/*
 * mb_core_spare4 
 * In order to solve the issue related to the energy injection in the MEMS when the power mode is changed, we need to null the input offset of the SC2V. To do this we have to use 3 more spare bits in the mbcore, which are already mapped in the OTP but the field name is missing from the regmap.
 */
#define MB_CORE_BAR_7_BYTE_2_MB_CORE_SPARE4_POS      0x00
#define MB_CORE_BAR_7_BYTE_2_MB_CORE_SPARE4_MASK     0x07



/*
 * ACC_CP_BAR_8_BYTE_0
 * Register Name : ACC_CP_BAR_8_BYTE_0
 */

/*
 * acc_cp_testmode 
 * test mode contol
 */
#define ACC_CP_BAR_8_BYTE_0_ACC_CP_TESTMODE_POS      0x00
#define ACC_CP_BAR_8_BYTE_0_ACC_CP_TESTMODE_MASK     0x07



/*
 * ACC_BIAS_BAR_9_BYTE_0
 * Register Name : ACC_BIAS_BAR_9_BYTE_0
 */

/*
 * pd_acc_bias_az_vrefshield_ovr_b 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_0_PD_ACC_BIAS_AZ_VREFSHIELD_OVR_B_POS      0x00
#define ACC_BIAS_BAR_9_BYTE_0_PD_ACC_BIAS_AZ_VREFSHIELD_OVR_B_MASK     0x01

/*
 * pd_acc_bias_axy_vrefshield_ovr_b 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_0_PD_ACC_BIAS_AXY_VREFSHIELD_OVR_B_POS      0x01
#define ACC_BIAS_BAR_9_BYTE_0_PD_ACC_BIAS_AXY_VREFSHIELD_OVR_B_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_0_PD_ACC_BIAS_AXY_VREFSHIELD_OVR_B_POS)

/*
 * rst_acc_bias_testbuffer_dmd_b 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_0_RST_ACC_BIAS_TESTBUFFER_DMD_B_POS      0x02
#define ACC_BIAS_BAR_9_BYTE_0_RST_ACC_BIAS_TESTBUFFER_DMD_B_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_0_RST_ACC_BIAS_TESTBUFFER_DMD_B_POS)

/*
 * rst_acc_bias_testbuffer 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_0_RST_ACC_BIAS_TESTBUFFER_POS      0x03
#define ACC_BIAS_BAR_9_BYTE_0_RST_ACC_BIAS_TESTBUFFER_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_0_RST_ACC_BIAS_TESTBUFFER_POS)

/*
 * pd_acc_bias_testbuffer_b 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_0_PD_ACC_BIAS_TESTBUFFER_B_POS      0x04
#define ACC_BIAS_BAR_9_BYTE_0_PD_ACC_BIAS_TESTBUFFER_B_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_0_PD_ACC_BIAS_TESTBUFFER_B_POS)

/*
 * en_acc_bias_testbuffer_sw_in1 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_SW_IN1_POS      0x05
#define ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_SW_IN1_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_SW_IN1_POS)

/*
 * en_acc_bias_testbuffer_sw_in2 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_SW_IN2_POS      0x06
#define ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_SW_IN2_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_SW_IN2_POS)

/*
 * en_acc_bias_testbuffer_higain 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_HIGAIN_POS      0x07
#define ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_HIGAIN_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_0_EN_ACC_BIAS_TESTBUFFER_HIGAIN_POS)



/*
 * ACC_BIAS_BAR_9_BYTE_1
 * Register Name : ACC_BIAS_BAR_9_BYTE_1
 */

/*
 * acc_bias_testbuffer_gain 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_1_ACC_BIAS_TESTBUFFER_GAIN_POS      0x00
#define ACC_BIAS_BAR_9_BYTE_1_ACC_BIAS_TESTBUFFER_GAIN_MASK     0x07

/*
 * pd_acc_bias_drivebuffer_ovr_b 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_1_PD_ACC_BIAS_DRIVEBUFFER_OVR_B_POS      0x03
#define ACC_BIAS_BAR_9_BYTE_1_PD_ACC_BIAS_DRIVEBUFFER_OVR_B_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_1_PD_ACC_BIAS_DRIVEBUFFER_OVR_B_POS)

/*
 * dis_acc_bias_drivebuffer_chop 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_1_DIS_ACC_BIAS_DRIVEBUFFER_CHOP_POS      0x04
#define ACC_BIAS_BAR_9_BYTE_1_DIS_ACC_BIAS_DRIVEBUFFER_CHOP_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_1_DIS_ACC_BIAS_DRIVEBUFFER_CHOP_POS)

/*
 * acc_bias_testmode 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_1_ACC_BIAS_TESTMODE_POS      0x05
#define ACC_BIAS_BAR_9_BYTE_1_ACC_BIAS_TESTMODE_MASK     (0x07 << ACC_BIAS_BAR_9_BYTE_1_ACC_BIAS_TESTMODE_POS)



/*
 * ACC_BIAS_BAR_9_BYTE_2
 * Register Name : ACC_BIAS_BAR_9_BYTE_2
 */

/*
 * acc_bias_hiz_axy 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_HIZ_AXY_POS      0x00
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_HIZ_AXY_MASK     0x01

/*
 * acc_bias_hiz_az 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_HIZ_AZ_POS      0x01
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_HIZ_AZ_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_HIZ_AZ_POS)

/*
 * acc_bias_dig_mask 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_DIG_MASK_POS      0x02
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_DIG_MASK_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_DIG_MASK_POS)

/*
 * acc_bias_vref0p7v_remap_ext 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_VREF0P7V_REMAP_EXT_POS      0x03
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_VREF0P7V_REMAP_EXT_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_VREF0P7V_REMAP_EXT_POS)

/*
 * en_acc_bias_drivebuffer_vd1p4v 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_2_EN_ACC_BIAS_DRIVEBUFFER_VD1P4V_POS      0x04
#define ACC_BIAS_BAR_9_BYTE_2_EN_ACC_BIAS_DRIVEBUFFER_VD1P4V_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_2_EN_ACC_BIAS_DRIVEBUFFER_VD1P4V_POS)

/*
 * acc_bias_cfg_spare 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_CFG_SPARE_POS      0x05
#define ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_CFG_SPARE_MASK     (0x07 << ACC_BIAS_BAR_9_BYTE_2_ACC_BIAS_CFG_SPARE_POS)



/*
 * ACC_BIAS_BAR_9_BYTE_3
 * Register Name : ACC_BIAS_BAR_9_BYTE_3
 */

/*
 * acc_bias_az_vrefshield 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_AZ_VREFSHIELD_POS      0x00
#define ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_AZ_VREFSHIELD_MASK     0x0f

/*
 * acc_bias_sel_clk_edge_drivebuffer 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_SEL_CLK_EDGE_DRIVEBUFFER_POS      0x04
#define ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_SEL_CLK_EDGE_DRIVEBUFFER_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_SEL_CLK_EDGE_DRIVEBUFFER_POS)

/*
 * acc_bias_dis_drivebuffer_chop 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_DIS_DRIVEBUFFER_CHOP_POS      0x05
#define ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_DIS_DRIVEBUFFER_CHOP_MASK     (0x01 << ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_DIS_DRIVEBUFFER_CHOP_POS)

/*
 * acc_bias_otp_spare 
 * nan
 */
#define ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_OTP_SPARE_POS      0x06
#define ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_OTP_SPARE_MASK     (0x03 << ACC_BIAS_BAR_9_BYTE_3_ACC_BIAS_OTP_SPARE_POS)



/*
 * MB_DREG_BAR_10_BYTE_0
 * Register Name : MB_DREG_BAR_10_BYTE_0
 */

/*
 * dreg_spare 
 * Spare bits not used
 */
#define MB_DREG_BAR_10_BYTE_0_DREG_SPARE_POS      0x00
#define MB_DREG_BAR_10_BYTE_0_DREG_SPARE_MASK     0x03

/*
 * dreg_set_vbg_up 
 * Dreg moved Up +60mV
 */
#define MB_DREG_BAR_10_BYTE_0_DREG_SET_VBG_UP_POS      0x02
#define MB_DREG_BAR_10_BYTE_0_DREG_SET_VBG_UP_MASK     (0x01 << MB_DREG_BAR_10_BYTE_0_DREG_SET_VBG_UP_POS)

/*
 * dreg_set_1meg_load 
 * 1 Meg resistor loading
 */
#define MB_DREG_BAR_10_BYTE_0_DREG_SET_1MEG_LOAD_POS      0x03
#define MB_DREG_BAR_10_BYTE_0_DREG_SET_1MEG_LOAD_MASK     (0x01 << MB_DREG_BAR_10_BYTE_0_DREG_SET_1MEG_LOAD_POS)

/*
 * dreg_dvdd 
 * Dreg voltage  trim
 */
#define MB_DREG_BAR_10_BYTE_0_DREG_DVDD_POS      0x04
#define MB_DREG_BAR_10_BYTE_0_DREG_DVDD_MASK     (0x0f << MB_DREG_BAR_10_BYTE_0_DREG_DVDD_POS)



/*
 * MB_DREG_BAR_10_BYTE_1
 * Register Name : MB_DREG_BAR_10_BYTE_1
 */

/*
 * dreg_testmode 
 * Test mode routing Dreg and Loacal gnd  to atp 1 and 0 respectly
 */
#define MB_DREG_BAR_10_BYTE_1_DREG_TESTMODE_POS      0x00
#define MB_DREG_BAR_10_BYTE_1_DREG_TESTMODE_MASK     0xff



/*
 * AMP_GSXYZ_BAR_11_BYTE_0
 * Register Name : AMP_GSXYZ_BAR_11_BYTE_0
 */

/*
 * gyro_sc2v_force 
 * 00=none, 01=force x axis, 10= force y axis, 11= force z axis
 */
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_FORCE_POS      0x06
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_FORCE_MASK     (0x03 << AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_FORCE_POS)

/*
 * gyro_sc2v_cont_mode 
 * soc capacitances continuous mode (it disables the soc caps)
 */
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_CONT_MODE_POS      0x05
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_CONT_MODE_MASK     (0x01 << AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_CONT_MODE_POS)

/*
 * gyro_sc2v_cdiff 
 * continuous differential mode enable (test mode)
 */
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_CDIFF_POS      0x04
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_CDIFF_MASK     (0x01 << AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_CDIFF_POS)

/*
 * gyro_sc2v_sep 
 * continuous single ended mode with p input (test mode)
 */
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_SEP_POS      0x03
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_SEP_MASK     (0x01 << AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_SEP_POS)

/*
 * gyro_sc2v_sen 
 * continuous single ended mode with n input (test mode)
 */
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_SEN_POS      0x02
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_SEN_MASK     (0x01 << AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_SEN_POS)

/*
 * gyro_sc2v_en_ghom 
 * gigahom resistance enable
 */
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_EN_GHOM_POS      0x01
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_EN_GHOM_MASK     (0x01 << AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_EN_GHOM_POS)

/*
 * gyro_sc2v_mask_rst_with_ghom 
 * reset disable when the ghom resistance is enabled
 */
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_MASK_RST_WITH_GHOM_POS      0x00
#define AMP_GSXYZ_BAR_11_BYTE_0_GYRO_SC2V_MASK_RST_WITH_GHOM_MASK     0x01



/*
 * AMP_GSXYZ_BAR_11_BYTE_1
 * Register Name : AMP_GSXYZ_BAR_11_BYTE_1
 */

/*
 * gyro_sc2v_en_fast_settling 
 * fast settling enable (suggested at high gain)
 */
#define AMP_GSXYZ_BAR_11_BYTE_1_GYRO_SC2V_EN_FAST_SETTLING_POS      0x07
#define AMP_GSXYZ_BAR_11_BYTE_1_GYRO_SC2V_EN_FAST_SETTLING_MASK     (0x01 << AMP_GSXYZ_BAR_11_BYTE_1_GYRO_SC2V_EN_FAST_SETTLING_POS)

/*
 * gyro_sc2v_ft_x 
 * quadrature compensation caps trimming for x-axis
 */
#define AMP_GSXYZ_BAR_11_BYTE_1_GYRO_SC2V_FT_X_POS      0x00
#define AMP_GSXYZ_BAR_11_BYTE_1_GYRO_SC2V_FT_X_MASK     0x7f



/*
 * AMP_GSXYZ_BAR_11_BYTE_2
 * Register Name : AMP_GSXYZ_BAR_11_BYTE_2
 */

/*
 * gyro_sc2v_en_all_cm_rst 
 * maximum reset Miller cap enable
 */
#define AMP_GSXYZ_BAR_11_BYTE_2_GYRO_SC2V_EN_ALL_CM_RST_POS      0x07
#define AMP_GSXYZ_BAR_11_BYTE_2_GYRO_SC2V_EN_ALL_CM_RST_MASK     (0x01 << AMP_GSXYZ_BAR_11_BYTE_2_GYRO_SC2V_EN_ALL_CM_RST_POS)

/*
 * gyro_sc2v_ft_y 
 * quadrature compensation caps trimming for y-axis
 */
#define AMP_GSXYZ_BAR_11_BYTE_2_GYRO_SC2V_FT_Y_POS      0x00
#define AMP_GSXYZ_BAR_11_BYTE_2_GYRO_SC2V_FT_Y_MASK     0x7f



/*
 * AMP_GSXYZ_BAR_11_BYTE_3
 * Register Name : AMP_GSXYZ_BAR_11_BYTE_3
 */

/*
 * gyro_sc2v_op_hc 
 * spare trim bit
 */
#define AMP_GSXYZ_BAR_11_BYTE_3_GYRO_SC2V_OP_HC_POS      0x07
#define AMP_GSXYZ_BAR_11_BYTE_3_GYRO_SC2V_OP_HC_MASK     (0x01 << AMP_GSXYZ_BAR_11_BYTE_3_GYRO_SC2V_OP_HC_POS)

/*
 * gyro_sc2v_ft_z 
 * quadrature compensation caps trimming for z-axis
 */
#define AMP_GSXYZ_BAR_11_BYTE_3_GYRO_SC2V_FT_Z_POS      0x00
#define AMP_GSXYZ_BAR_11_BYTE_3_GYRO_SC2V_FT_Z_MASK     0x7f



/*
 * AMP_GSXYZ_BAR_12_BYTE_0
 * Register Name : AMP_GSXYZ_BAR_12_BYTE_0
 */

/*
 * gyro_sc2v_soc_x 
 * static offset compensation (soc) trimming for x-axis
 */
#define AMP_GSXYZ_BAR_12_BYTE_0_GYRO_SC2V_SOC_X_POS      0x00
#define AMP_GSXYZ_BAR_12_BYTE_0_GYRO_SC2V_SOC_X_MASK     0xff



/*
 * AMP_GSXYZ_BAR_12_BYTE_1
 * Register Name : AMP_GSXYZ_BAR_12_BYTE_1
 */

/*
 * gyro_sc2v_soc_y 
 * static offset compensation (soc) trimming for y-axis
 */
#define AMP_GSXYZ_BAR_12_BYTE_1_GYRO_SC2V_SOC_Y_POS      0x00
#define AMP_GSXYZ_BAR_12_BYTE_1_GYRO_SC2V_SOC_Y_MASK     0xff



/*
 * AMP_GSXYZ_BAR_12_BYTE_2
 * Register Name : AMP_GSXYZ_BAR_12_BYTE_2
 */

/*
 * gyro_sc2v_soc_z 
 * static offset compensation (soc) trimming for z-axis
 */
#define AMP_GSXYZ_BAR_12_BYTE_2_GYRO_SC2V_SOC_Z_POS      0x00
#define AMP_GSXYZ_BAR_12_BYTE_2_GYRO_SC2V_SOC_Z_MASK     0xff



/*
 * AMP_GSXYZ_BAR_12_BYTE_3
 * Register Name : AMP_GSXYZ_BAR_12_BYTE_3
 */

/*
 * gyro_sc2v_testmode 
 * test mode selection
 */
#define AMP_GSXYZ_BAR_12_BYTE_3_GYRO_SC2V_TESTMODE_POS      0x00
#define AMP_GSXYZ_BAR_12_BYTE_3_GYRO_SC2V_TESTMODE_MASK     0xff



/*
 * AMP_GSXYZ_BAR_13_BYTE_0
 * Register Name : AMP_GSXYZ_BAR_13_BYTE_0
 */

/*
 * gyro_sc2v_bopole 
 * opamp output pole trimming (stability/bandwidth)
 */
#define AMP_GSXYZ_BAR_13_BYTE_0_GYRO_SC2V_BOPOLE_POS      0x06
#define AMP_GSXYZ_BAR_13_BYTE_0_GYRO_SC2V_BOPOLE_MASK     (0x03 << AMP_GSXYZ_BAR_13_BYTE_0_GYRO_SC2V_BOPOLE_POS)

/*
 * gyro_sc2v_bptat1_ut 
 * opamp 1st stage current trimming (noise/power)
 */
#define AMP_GSXYZ_BAR_13_BYTE_0_GYRO_SC2V_BPTAT1_UT_POS      0x03
#define AMP_GSXYZ_BAR_13_BYTE_0_GYRO_SC2V_BPTAT1_UT_MASK     (0x07 << AMP_GSXYZ_BAR_13_BYTE_0_GYRO_SC2V_BPTAT1_UT_POS)

/*
 * gyro_sc2v_bptat2_ut 
 * opamp 2st stage current trimming (noise/power)
 */
#define AMP_GSXYZ_BAR_13_BYTE_0_GYRO_SC2V_BPTAT2_UT_POS      0x00
#define AMP_GSXYZ_BAR_13_BYTE_0_GYRO_SC2V_BPTAT2_UT_MASK     0x07



/*
 * AMP_GSXYZ_BAR_13_BYTE_1
 * Register Name : AMP_GSXYZ_BAR_13_BYTE_1
 */

/*
 * gyro_sc2v_bptat_t 
 * opamp 3rd and 4th stages current trimming (noise/power)
 */
#define AMP_GSXYZ_BAR_13_BYTE_1_GYRO_SC2V_BPTAT_T_POS      0x04
#define AMP_GSXYZ_BAR_13_BYTE_1_GYRO_SC2V_BPTAT_T_MASK     (0x0f << AMP_GSXYZ_BAR_13_BYTE_1_GYRO_SC2V_BPTAT_T_POS)

/*
 * gyro_sc2v_bcorr_coarse 
 * opamp 3rd and 4th stages current blend trimming
 */
#define AMP_GSXYZ_BAR_13_BYTE_1_GYRO_SC2V_BCORR_COARSE_POS      0x00
#define AMP_GSXYZ_BAR_13_BYTE_1_GYRO_SC2V_BCORR_COARSE_MASK     0x0f



/*
 * AMP_GSXYZ_BAR_13_BYTE_2
 * Register Name : AMP_GSXYZ_BAR_13_BYTE_2
 */

/*
 * gyro_cp_aways_on 
 * 3v charge pump always on mode
 */
#define AMP_GSXYZ_BAR_13_BYTE_2_GYRO_CP_AWAYS_ON_POS      0x07
#define AMP_GSXYZ_BAR_13_BYTE_2_GYRO_CP_AWAYS_ON_MASK     (0x01 << AMP_GSXYZ_BAR_13_BYTE_2_GYRO_CP_AWAYS_ON_POS)

/*
 * gyro_sc2v_en_rd 
 * common mode feedback gm control
 */
#define AMP_GSXYZ_BAR_13_BYTE_2_GYRO_SC2V_EN_RD_POS      0x06
#define AMP_GSXYZ_BAR_13_BYTE_2_GYRO_SC2V_EN_RD_MASK     (0x01 << AMP_GSXYZ_BAR_13_BYTE_2_GYRO_SC2V_EN_RD_POS)

/*
 * gyro_sc2v_en_cmfb_cap 
 * common mode feedback capacitive attenuation enable
 */
#define AMP_GSXYZ_BAR_13_BYTE_2_GYRO_SC2V_EN_CMFB_CAP_POS      0x05
#define AMP_GSXYZ_BAR_13_BYTE_2_GYRO_SC2V_EN_CMFB_CAP_MASK     (0x01 << AMP_GSXYZ_BAR_13_BYTE_2_GYRO_SC2V_EN_CMFB_CAP_POS)

/*
 * gyro_sc2v_bcorr_fine 
 * opamp 1st stage current blend trimming
 */
#define AMP_GSXYZ_BAR_13_BYTE_2_GYRO_SC2V_BCORR_FINE_POS      0x00
#define AMP_GSXYZ_BAR_13_BYTE_2_GYRO_SC2V_BCORR_FINE_MASK     0x1f



/*
 * AMP_GSXYZ_BAR_13_BYTE_3
 * Register Name : AMP_GSXYZ_BAR_13_BYTE_3
 */

/*
 * gyro_sc2v_cfg_spare 
 * spare config bits
 */
#define AMP_GSXYZ_BAR_13_BYTE_3_GYRO_SC2V_CFG_SPARE_POS      0x06
#define AMP_GSXYZ_BAR_13_BYTE_3_GYRO_SC2V_CFG_SPARE_MASK     (0x03 << AMP_GSXYZ_BAR_13_BYTE_3_GYRO_SC2V_CFG_SPARE_POS)

/*
 * gyro_sc2v_sel_off_force 
 * force all axis off, to be used in debug only
 */
#define AMP_GSXYZ_BAR_13_BYTE_3_GYRO_SC2V_SEL_OFF_FORCE_POS      0x05
#define AMP_GSXYZ_BAR_13_BYTE_3_GYRO_SC2V_SEL_OFF_FORCE_MASK     (0x01 << AMP_GSXYZ_BAR_13_BYTE_3_GYRO_SC2V_SEL_OFF_FORCE_POS)

/*
 * gyro_sc2v_res_code 
 * ghom resistance configuration
 */
#define AMP_GSXYZ_BAR_13_BYTE_3_GYRO_SC2V_RES_CODE_POS      0x00
#define AMP_GSXYZ_BAR_13_BYTE_3_GYRO_SC2V_RES_CODE_MASK     0x1f



/*
 * AMP_GSXYZ_BAR_14_BYTE_0
 * Register Name : AMP_GSXYZ_BAR_14_BYTE_0
 */

/*
 * gyro_sc2v_hfs_cfb_term_x 
 * high full scale Cfb trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_X_POS      0x06
#define AMP_GSXYZ_BAR_14_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_X_MASK     (0x03 << AMP_GSXYZ_BAR_14_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_X_POS)

/*
 * gyro_sc2v_hfs_cfb_x 
 * high full scale Cfb trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_0_GYRO_SC2V_HFS_CFB_X_POS      0x02
#define AMP_GSXYZ_BAR_14_BYTE_0_GYRO_SC2V_HFS_CFB_X_MASK     (0x0f << AMP_GSXYZ_BAR_14_BYTE_0_GYRO_SC2V_HFS_CFB_X_POS)

/*
 * gyro_sc2v_hfs_cfb_fine_x 
 * high full scale Cfb trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_0_GYRO_SC2V_HFS_CFB_FINE_X_POS      0x00
#define AMP_GSXYZ_BAR_14_BYTE_0_GYRO_SC2V_HFS_CFB_FINE_X_MASK     0x03



/*
 * AMP_GSXYZ_BAR_14_BYTE_1
 * Register Name : AMP_GSXYZ_BAR_14_BYTE_1
 */

/*
 * gyro_sc2v_lfs_cfb_term_x 
 * low full scale Cfb trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_X_POS      0x06
#define AMP_GSXYZ_BAR_14_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_X_MASK     (0x03 << AMP_GSXYZ_BAR_14_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_X_POS)

/*
 * gyro_sc2v_lfs_cfb_x 
 * low full scale Cfb trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_1_GYRO_SC2V_LFS_CFB_X_POS      0x02
#define AMP_GSXYZ_BAR_14_BYTE_1_GYRO_SC2V_LFS_CFB_X_MASK     (0x0f << AMP_GSXYZ_BAR_14_BYTE_1_GYRO_SC2V_LFS_CFB_X_POS)

/*
 * gyro_sc2v_lfs_cfb_fine_x 
 * low full scale Cfb trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_1_GYRO_SC2V_LFS_CFB_FINE_X_POS      0x00
#define AMP_GSXYZ_BAR_14_BYTE_1_GYRO_SC2V_LFS_CFB_FINE_X_MASK     0x03



/*
 * AMP_GSXYZ_BAR_14_BYTE_2
 * Register Name : AMP_GSXYZ_BAR_14_BYTE_2
 */

/*
 * gyro_sc2v_hfs_cm_term_x 
 * high full scale Miller cap Cm trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_2_GYRO_SC2V_HFS_CM_TERM_X_POS      0x06
#define AMP_GSXYZ_BAR_14_BYTE_2_GYRO_SC2V_HFS_CM_TERM_X_MASK     (0x03 << AMP_GSXYZ_BAR_14_BYTE_2_GYRO_SC2V_HFS_CM_TERM_X_POS)

/*
 * gyro_sc2v_hfs_cm_x 
 * high full scale Miller cap Cm trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_2_GYRO_SC2V_HFS_CM_X_POS      0x02
#define AMP_GSXYZ_BAR_14_BYTE_2_GYRO_SC2V_HFS_CM_X_MASK     (0x0f << AMP_GSXYZ_BAR_14_BYTE_2_GYRO_SC2V_HFS_CM_X_POS)

/*
 * gyro_sc2v_hfs_cm_fine_x 
 * high full scale Miller cap Cm trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_2_GYRO_SC2V_HFS_CM_FINE_X_POS      0x00
#define AMP_GSXYZ_BAR_14_BYTE_2_GYRO_SC2V_HFS_CM_FINE_X_MASK     0x03



/*
 * AMP_GSXYZ_BAR_14_BYTE_3
 * Register Name : AMP_GSXYZ_BAR_14_BYTE_3
 */

/*
 * gyro_sc2v_lfs_cm_term_x 
 * low full scale Miller cap Cm trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_3_GYRO_SC2V_LFS_CM_TERM_X_POS      0x06
#define AMP_GSXYZ_BAR_14_BYTE_3_GYRO_SC2V_LFS_CM_TERM_X_MASK     (0x03 << AMP_GSXYZ_BAR_14_BYTE_3_GYRO_SC2V_LFS_CM_TERM_X_POS)

/*
 * gyro_sc2v_lfs_cm_x 
 * low full scale Miller cap Cm trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_3_GYRO_SC2V_LFS_CM_X_POS      0x02
#define AMP_GSXYZ_BAR_14_BYTE_3_GYRO_SC2V_LFS_CM_X_MASK     (0x0f << AMP_GSXYZ_BAR_14_BYTE_3_GYRO_SC2V_LFS_CM_X_POS)

/*
 * gyro_sc2v_lfs_cm_fine_x 
 * low full scale Miller cap Cm trimming for x-axis
 */
#define AMP_GSXYZ_BAR_14_BYTE_3_GYRO_SC2V_LFS_CM_FINE_X_POS      0x00
#define AMP_GSXYZ_BAR_14_BYTE_3_GYRO_SC2V_LFS_CM_FINE_X_MASK     0x03



/*
 * AMP_GSXYZ_BAR_15_BYTE_0
 * Register Name : AMP_GSXYZ_BAR_15_BYTE_0
 */

/*
 * gyro_sc2v_hfs_cfb_term_y 
 * high full scale Cfb trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_Y_POS      0x06
#define AMP_GSXYZ_BAR_15_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_Y_MASK     (0x03 << AMP_GSXYZ_BAR_15_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_Y_POS)

/*
 * gyro_sc2v_hfs_cfb_y 
 * high full scale Cfb trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_0_GYRO_SC2V_HFS_CFB_Y_POS      0x02
#define AMP_GSXYZ_BAR_15_BYTE_0_GYRO_SC2V_HFS_CFB_Y_MASK     (0x0f << AMP_GSXYZ_BAR_15_BYTE_0_GYRO_SC2V_HFS_CFB_Y_POS)

/*
 * gyro_sc2v_hfs_cfb_fine_y 
 * high full scale Cfb trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_0_GYRO_SC2V_HFS_CFB_FINE_Y_POS      0x00
#define AMP_GSXYZ_BAR_15_BYTE_0_GYRO_SC2V_HFS_CFB_FINE_Y_MASK     0x03



/*
 * AMP_GSXYZ_BAR_15_BYTE_1
 * Register Name : AMP_GSXYZ_BAR_15_BYTE_1
 */

/*
 * gyro_sc2v_lfs_cfb_term_y 
 * low full scale Cfb trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_Y_POS      0x06
#define AMP_GSXYZ_BAR_15_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_Y_MASK     (0x03 << AMP_GSXYZ_BAR_15_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_Y_POS)

/*
 * gyro_sc2v_lfs_cfb_y 
 * low full scale Cfb trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_1_GYRO_SC2V_LFS_CFB_Y_POS      0x02
#define AMP_GSXYZ_BAR_15_BYTE_1_GYRO_SC2V_LFS_CFB_Y_MASK     (0x0f << AMP_GSXYZ_BAR_15_BYTE_1_GYRO_SC2V_LFS_CFB_Y_POS)

/*
 * gyro_sc2v_lfs_cfb_fine_y 
 * low full scale Cfb trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_1_GYRO_SC2V_LFS_CFB_FINE_Y_POS      0x00
#define AMP_GSXYZ_BAR_15_BYTE_1_GYRO_SC2V_LFS_CFB_FINE_Y_MASK     0x03



/*
 * AMP_GSXYZ_BAR_15_BYTE_2
 * Register Name : AMP_GSXYZ_BAR_15_BYTE_2
 */

/*
 * gyro_sc2v_hfs_cm_term_y 
 * high full scale Miller cap Cm trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_2_GYRO_SC2V_HFS_CM_TERM_Y_POS      0x06
#define AMP_GSXYZ_BAR_15_BYTE_2_GYRO_SC2V_HFS_CM_TERM_Y_MASK     (0x03 << AMP_GSXYZ_BAR_15_BYTE_2_GYRO_SC2V_HFS_CM_TERM_Y_POS)

/*
 * gyro_sc2v_hfs_cm_y 
 * high full scale Miller cap Cm trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_2_GYRO_SC2V_HFS_CM_Y_POS      0x02
#define AMP_GSXYZ_BAR_15_BYTE_2_GYRO_SC2V_HFS_CM_Y_MASK     (0x0f << AMP_GSXYZ_BAR_15_BYTE_2_GYRO_SC2V_HFS_CM_Y_POS)

/*
 * gyro_sc2v_hfs_cm_fine_y 
 * high full scale Miller cap Cm trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_2_GYRO_SC2V_HFS_CM_FINE_Y_POS      0x00
#define AMP_GSXYZ_BAR_15_BYTE_2_GYRO_SC2V_HFS_CM_FINE_Y_MASK     0x03



/*
 * AMP_GSXYZ_BAR_15_BYTE_3
 * Register Name : AMP_GSXYZ_BAR_15_BYTE_3
 */

/*
 * gyro_sc2v_lfs_cm_term_y 
 * low full scale Miller cap Cm trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_3_GYRO_SC2V_LFS_CM_TERM_Y_POS      0x06
#define AMP_GSXYZ_BAR_15_BYTE_3_GYRO_SC2V_LFS_CM_TERM_Y_MASK     (0x03 << AMP_GSXYZ_BAR_15_BYTE_3_GYRO_SC2V_LFS_CM_TERM_Y_POS)

/*
 * gyro_sc2v_lfs_cm_y 
 * low full scale Miller cap Cm trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_3_GYRO_SC2V_LFS_CM_Y_POS      0x02
#define AMP_GSXYZ_BAR_15_BYTE_3_GYRO_SC2V_LFS_CM_Y_MASK     (0x0f << AMP_GSXYZ_BAR_15_BYTE_3_GYRO_SC2V_LFS_CM_Y_POS)

/*
 * gyro_sc2v_lfs_cm_fine_y 
 * low full scale Miller cap Cm trimming for y-axis
 */
#define AMP_GSXYZ_BAR_15_BYTE_3_GYRO_SC2V_LFS_CM_FINE_Y_POS      0x00
#define AMP_GSXYZ_BAR_15_BYTE_3_GYRO_SC2V_LFS_CM_FINE_Y_MASK     0x03



/*
 * AMP_GSXYZ_BAR_16_BYTE_0
 * Register Name : AMP_GSXYZ_BAR_16_BYTE_0
 */

/*
 * gyro_sc2v_hfs_cfb_term_z 
 * high full scale Cfb trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_Z_POS      0x06
#define AMP_GSXYZ_BAR_16_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_Z_MASK     (0x03 << AMP_GSXYZ_BAR_16_BYTE_0_GYRO_SC2V_HFS_CFB_TERM_Z_POS)

/*
 * gyro_sc2v_hfs_cfb_z 
 * high full scale Cfb trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_0_GYRO_SC2V_HFS_CFB_Z_POS      0x02
#define AMP_GSXYZ_BAR_16_BYTE_0_GYRO_SC2V_HFS_CFB_Z_MASK     (0x0f << AMP_GSXYZ_BAR_16_BYTE_0_GYRO_SC2V_HFS_CFB_Z_POS)

/*
 * gyro_sc2v_hfs_cfb_fine_z 
 * high full scale Cfb trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_0_GYRO_SC2V_HFS_CFB_FINE_Z_POS      0x00
#define AMP_GSXYZ_BAR_16_BYTE_0_GYRO_SC2V_HFS_CFB_FINE_Z_MASK     0x03



/*
 * AMP_GSXYZ_BAR_16_BYTE_1
 * Register Name : AMP_GSXYZ_BAR_16_BYTE_1
 */

/*
 * gyro_sc2v_lfs_cfb_term_z 
 * low full scale Cfb trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_Z_POS      0x06
#define AMP_GSXYZ_BAR_16_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_Z_MASK     (0x03 << AMP_GSXYZ_BAR_16_BYTE_1_GYRO_SC2V_LFS_CFB_TERM_Z_POS)

/*
 * gyro_sc2v_lfs_cfb_z 
 * low full scale Cfb trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_1_GYRO_SC2V_LFS_CFB_Z_POS      0x02
#define AMP_GSXYZ_BAR_16_BYTE_1_GYRO_SC2V_LFS_CFB_Z_MASK     (0x0f << AMP_GSXYZ_BAR_16_BYTE_1_GYRO_SC2V_LFS_CFB_Z_POS)

/*
 * gyro_sc2v_lfs_cfb_fine_z 
 * low full scale Cfb trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_1_GYRO_SC2V_LFS_CFB_FINE_Z_POS      0x00
#define AMP_GSXYZ_BAR_16_BYTE_1_GYRO_SC2V_LFS_CFB_FINE_Z_MASK     0x03



/*
 * AMP_GSXYZ_BAR_16_BYTE_2
 * Register Name : AMP_GSXYZ_BAR_16_BYTE_2
 */

/*
 * gyro_sc2v_hfs_cm_term_z 
 * high full scale Miller cap Cm trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_2_GYRO_SC2V_HFS_CM_TERM_Z_POS      0x06
#define AMP_GSXYZ_BAR_16_BYTE_2_GYRO_SC2V_HFS_CM_TERM_Z_MASK     (0x03 << AMP_GSXYZ_BAR_16_BYTE_2_GYRO_SC2V_HFS_CM_TERM_Z_POS)

/*
 * gyro_sc2v_hfs_cm_z 
 * high full scale Miller cap Cm trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_2_GYRO_SC2V_HFS_CM_Z_POS      0x02
#define AMP_GSXYZ_BAR_16_BYTE_2_GYRO_SC2V_HFS_CM_Z_MASK     (0x0f << AMP_GSXYZ_BAR_16_BYTE_2_GYRO_SC2V_HFS_CM_Z_POS)

/*
 * gyro_sc2v_hfs_cm_fine_z 
 * high full scale Miller cap Cm trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_2_GYRO_SC2V_HFS_CM_FINE_Z_POS      0x00
#define AMP_GSXYZ_BAR_16_BYTE_2_GYRO_SC2V_HFS_CM_FINE_Z_MASK     0x03



/*
 * AMP_GSXYZ_BAR_16_BYTE_3
 * Register Name : AMP_GSXYZ_BAR_16_BYTE_3
 */

/*
 * gyro_sc2v_lfs_cm_term_z 
 * low full scale Miller cap Cm trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_3_GYRO_SC2V_LFS_CM_TERM_Z_POS      0x06
#define AMP_GSXYZ_BAR_16_BYTE_3_GYRO_SC2V_LFS_CM_TERM_Z_MASK     (0x03 << AMP_GSXYZ_BAR_16_BYTE_3_GYRO_SC2V_LFS_CM_TERM_Z_POS)

/*
 * gyro_sc2v_lfs_cm_z 
 * low full scale Miller cap Cm trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_3_GYRO_SC2V_LFS_CM_Z_POS      0x02
#define AMP_GSXYZ_BAR_16_BYTE_3_GYRO_SC2V_LFS_CM_Z_MASK     (0x0f << AMP_GSXYZ_BAR_16_BYTE_3_GYRO_SC2V_LFS_CM_Z_POS)

/*
 * gyro_sc2v_lfs_cm_fine_z 
 * low full scale Miller cap Cm trimming for z-axis
 */
#define AMP_GSXYZ_BAR_16_BYTE_3_GYRO_SC2V_LFS_CM_FINE_Z_POS      0x00
#define AMP_GSXYZ_BAR_16_BYTE_3_GYRO_SC2V_LFS_CM_FINE_Z_MASK     0x03



/*
 * ACC_XYZ_BAR_18_BYTE_0
 * Register Name : ACC_XYZ_BAR_18_BYTE_0
 */

/*
 * accel_spare 
 * nan
 */
#define ACC_XYZ_BAR_18_BYTE_0_ACCEL_SPARE_POS      0x00
#define ACC_XYZ_BAR_18_BYTE_0_ACCEL_SPARE_MASK     0x1f

/*
 * accel_c2v_test_bypass_en 
 * nan
 */
#define ACC_XYZ_BAR_18_BYTE_0_ACCEL_C2V_TEST_BYPASS_EN_POS      0x05
#define ACC_XYZ_BAR_18_BYTE_0_ACCEL_C2V_TEST_BYPASS_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_0_ACCEL_C2V_TEST_BYPASS_EN_POS)

/*
 * accel_testmode 
 * testmodes enabling signals for all axis
 */
#define ACC_XYZ_BAR_18_BYTE_0_ACCEL_TESTMODE_POS      0x06
#define ACC_XYZ_BAR_18_BYTE_0_ACCEL_TESTMODE_MASK     (0x03 << ACC_XYZ_BAR_18_BYTE_0_ACCEL_TESTMODE_POS)



/*
 * ACC_XYZ_BAR_18_BYTE_1
 * Register Name : ACC_XYZ_BAR_18_BYTE_1
 */

/*
 * ax_st_ext_en 
 * nan
 */
#define ACC_XYZ_BAR_18_BYTE_1_AX_ST_EXT_EN_POS      0x00
#define ACC_XYZ_BAR_18_BYTE_1_AX_ST_EXT_EN_MASK     0x01

/*
 * ay_st_ext_en 
 * nan
 */
#define ACC_XYZ_BAR_18_BYTE_1_AY_ST_EXT_EN_POS      0x01
#define ACC_XYZ_BAR_18_BYTE_1_AY_ST_EXT_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_1_AY_ST_EXT_EN_POS)

/*
 * az_st_ext_en 
 * nan
 */
#define ACC_XYZ_BAR_18_BYTE_1_AZ_ST_EXT_EN_POS      0x02
#define ACC_XYZ_BAR_18_BYTE_1_AZ_ST_EXT_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_1_AZ_ST_EXT_EN_POS)

/*
 * accel_c2v_cmos_only_mode 
 * nan
 */
#define ACC_XYZ_BAR_18_BYTE_1_ACCEL_C2V_CMOS_ONLY_MODE_POS      0x03
#define ACC_XYZ_BAR_18_BYTE_1_ACCEL_C2V_CMOS_ONLY_MODE_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_1_ACCEL_C2V_CMOS_ONLY_MODE_POS)

/*
 * accel_c2v_drive_reset_off 
 * disable PM drive reset to 1.25V for all axis
 */
#define ACC_XYZ_BAR_18_BYTE_1_ACCEL_C2V_DRIVE_RESET_OFF_POS      0x04
#define ACC_XYZ_BAR_18_BYTE_1_ACCEL_C2V_DRIVE_RESET_OFF_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_1_ACCEL_C2V_DRIVE_RESET_OFF_POS)

/*
 * pd_ax_c2v_drive_b 
 * enable x-axis 0-2.5V PM drive (enabled by default)
 */
#define ACC_XYZ_BAR_18_BYTE_1_PD_AX_C2V_DRIVE_B_POS      0x05
#define ACC_XYZ_BAR_18_BYTE_1_PD_AX_C2V_DRIVE_B_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_1_PD_AX_C2V_DRIVE_B_POS)

/*
 * pd_ay_c2v_drive_b 
 * enable y-axis 0-2.5V PM drive (enabled by default)
 */
#define ACC_XYZ_BAR_18_BYTE_1_PD_AY_C2V_DRIVE_B_POS      0x06
#define ACC_XYZ_BAR_18_BYTE_1_PD_AY_C2V_DRIVE_B_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_1_PD_AY_C2V_DRIVE_B_POS)

/*
 * pd_az_c2v_drive_b 
 * enable z-axis 0-2.5V PM drive (enabled by default)
 */
#define ACC_XYZ_BAR_18_BYTE_1_PD_AZ_C2V_DRIVE_B_POS      0x07
#define ACC_XYZ_BAR_18_BYTE_1_PD_AZ_C2V_DRIVE_B_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_1_PD_AZ_C2V_DRIVE_B_POS)



/*
 * ACC_XYZ_BAR_18_BYTE_2
 * Register Name : ACC_XYZ_BAR_18_BYTE_2
 */

/*
 * accel_c2v_as_mode 
 * PM driving configurations: set to 1 for PM1 only
 */
#define ACC_XYZ_BAR_18_BYTE_2_ACCEL_C2V_AS_MODE_POS      0x00
#define ACC_XYZ_BAR_18_BYTE_2_ACCEL_C2V_AS_MODE_MASK     0x03

/*
 * ax_gs0_en 
 * enable x-axis GS0 electrode connection to test buffer (otherwise connected to Vrefshield)
 */
#define ACC_XYZ_BAR_18_BYTE_2_AX_GS0_EN_POS      0x02
#define ACC_XYZ_BAR_18_BYTE_2_AX_GS0_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_2_AX_GS0_EN_POS)

/*
 * ax_gs1_en 
 * enable x-axis GS1 electrode connection to test buffer (otherwise connected to Vrefshield)
 */
#define ACC_XYZ_BAR_18_BYTE_2_AX_GS1_EN_POS      0x03
#define ACC_XYZ_BAR_18_BYTE_2_AX_GS1_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_2_AX_GS1_EN_POS)

/*
 * ay_gs0_en 
 * enable y-axis GS0 electrode connection to test buffer (otherwise connected to Vrefshield)
 */
#define ACC_XYZ_BAR_18_BYTE_2_AY_GS0_EN_POS      0x04
#define ACC_XYZ_BAR_18_BYTE_2_AY_GS0_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_2_AY_GS0_EN_POS)

/*
 * ay_gs1_en 
 * enable y-axis GS1 electrode connection to test buffer (otherwise connected to Vrefshield)
 */
#define ACC_XYZ_BAR_18_BYTE_2_AY_GS1_EN_POS      0x05
#define ACC_XYZ_BAR_18_BYTE_2_AY_GS1_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_2_AY_GS1_EN_POS)

/*
 * ax_mt_en 
 * enable x-axis MT electrode connection to PM1 (otherwise connected to Vrefshield)
 */
#define ACC_XYZ_BAR_18_BYTE_2_AX_MT_EN_POS      0x06
#define ACC_XYZ_BAR_18_BYTE_2_AX_MT_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_2_AX_MT_EN_POS)

/*
 * ay_mt_en 
 * enable y-axis MT electrode connection to PM1 (otherwise connected to Vrefshield)
 */
#define ACC_XYZ_BAR_18_BYTE_2_AY_MT_EN_POS      0x07
#define ACC_XYZ_BAR_18_BYTE_2_AY_MT_EN_MASK     (0x01 << ACC_XYZ_BAR_18_BYTE_2_AY_MT_EN_POS)



/*
 * ACC_XYZ_BAR_18_BYTE_3
 * Register Name : ACC_XYZ_BAR_18_BYTE_3
 */

/*
 * accel_otp_spare 
 * nan
 */
#define ACC_XYZ_BAR_18_BYTE_3_ACCEL_OTP_SPARE_POS      0x00
#define ACC_XYZ_BAR_18_BYTE_3_ACCEL_OTP_SPARE_MASK     0xff



/*
 * ACC_XYZ_BAR_19_BYTE_0
 * Register Name : ACC_XYZ_BAR_19_BYTE_0
 */

/*
 * ax_ft 
 * x-axis feedthrough cap trim
 */
#define ACC_XYZ_BAR_19_BYTE_0_AX_FT_POS      0x00
#define ACC_XYZ_BAR_19_BYTE_0_AX_FT_MASK     0x3f

/*
 * ay_ft 
 * y-axis feedthrough cap trim
 */
#define ACC_XYZ_BAR_19_BYTE_0_AY_FT_POS      0x06
#define ACC_XYZ_BAR_19_BYTE_0_AY_FT_MASK     (0x03 << ACC_XYZ_BAR_19_BYTE_0_AY_FT_POS)



/*
 * ACC_XYZ_BAR_19_BYTE_1
 * Register Name : ACC_XYZ_BAR_19_BYTE_1
 */

/*
 * ay_ft 
 * y-axis feedthrough cap trim
 */
#define ACC_XYZ_BAR_19_BYTE_1_AY_FT_POS      0x00
#define ACC_XYZ_BAR_19_BYTE_1_AY_FT_MASK     0x0f

/*
 * az_ft 
 * z-axis feedthrough cap trim
 */
#define ACC_XYZ_BAR_19_BYTE_1_AZ_FT_POS      0x04
#define ACC_XYZ_BAR_19_BYTE_1_AZ_FT_MASK     (0x0f << ACC_XYZ_BAR_19_BYTE_1_AZ_FT_POS)



/*
 * ACC_XYZ_BAR_19_BYTE_2
 * Register Name : ACC_XYZ_BAR_19_BYTE_2
 */

/*
 * az_ft 
 * z-axis feedthrough cap trim
 */
#define ACC_XYZ_BAR_19_BYTE_2_AZ_FT_POS      0x00
#define ACC_XYZ_BAR_19_BYTE_2_AZ_FT_MASK     0x03

/*
 * accel_c2v_highsens 
 * additional capacitance for c2v Miller compensation
 */
#define ACC_XYZ_BAR_19_BYTE_2_ACCEL_C2V_HIGHSENS_POS      0x02
#define ACC_XYZ_BAR_19_BYTE_2_ACCEL_C2V_HIGHSENS_MASK     (0x01 << ACC_XYZ_BAR_19_BYTE_2_ACCEL_C2V_HIGHSENS_POS)

/*
 * az_c2v_snsref_pol 
 * AS11, AS21 connection polarity to AS1, AS2
 */
#define ACC_XYZ_BAR_19_BYTE_2_AZ_C2V_SNSREF_POL_POS      0x03
#define ACC_XYZ_BAR_19_BYTE_2_AZ_C2V_SNSREF_POL_MASK     (0x01 << ACC_XYZ_BAR_19_BYTE_2_AZ_C2V_SNSREF_POL_POS)

/*
 * az_cd 
 * z-axis HB sense capacitance trim
 */
#define ACC_XYZ_BAR_19_BYTE_2_AZ_CD_POS      0x04
#define ACC_XYZ_BAR_19_BYTE_2_AZ_CD_MASK     (0x0f << ACC_XYZ_BAR_19_BYTE_2_AZ_CD_POS)



/*
 * ACC_XYZ_BAR_19_BYTE_3
 * Register Name : ACC_XYZ_BAR_19_BYTE_3
 */

/*
 * az_cpmgnd 
 * z-axis HB AS-gnd capacitance trim
 */
#define ACC_XYZ_BAR_19_BYTE_3_AZ_CPMGND_POS      0x00
#define ACC_XYZ_BAR_19_BYTE_3_AZ_CPMGND_MASK     0x0f

/*
 * az_cpmsh 
 * z-axis HB AS-shield capacitance trim
 */
#define ACC_XYZ_BAR_19_BYTE_3_AZ_CPMSH_POS      0x04
#define ACC_XYZ_BAR_19_BYTE_3_AZ_CPMSH_MASK     (0x0f << ACC_XYZ_BAR_19_BYTE_3_AZ_CPMSH_POS)



/*
 * ACC_XYZ_BAR_20_BYTE_0
 * Register Name : ACC_XYZ_BAR_20_BYTE_0
 */

/*
 * az_cpmazsh 
 * z-axis HB AS-azshield capacitance trim
 */
#define ACC_XYZ_BAR_20_BYTE_0_AZ_CPMAZSH_POS      0x00
#define ACC_XYZ_BAR_20_BYTE_0_AZ_CPMAZSH_MASK     0x0f

/*
 * ax_cd 
 * x-axis HB sense capacitance trim
 */
#define ACC_XYZ_BAR_20_BYTE_0_AX_CD_POS      0x04
#define ACC_XYZ_BAR_20_BYTE_0_AX_CD_MASK     (0x0f << ACC_XYZ_BAR_20_BYTE_0_AX_CD_POS)



/*
 * ACC_XYZ_BAR_20_BYTE_1
 * Register Name : ACC_XYZ_BAR_20_BYTE_1
 */

/*
 * ax_cpmgnd 
 * x-axis HB AS-gnd capacitance trim
 */
#define ACC_XYZ_BAR_20_BYTE_1_AX_CPMGND_POS      0x00
#define ACC_XYZ_BAR_20_BYTE_1_AX_CPMGND_MASK     0x0f

/*
 * ax_cpmsh 
 * x-axis HB AS-shield capacitance trim
 */
#define ACC_XYZ_BAR_20_BYTE_1_AX_CPMSH_POS      0x04
#define ACC_XYZ_BAR_20_BYTE_1_AX_CPMSH_MASK     (0x0f << ACC_XYZ_BAR_20_BYTE_1_AX_CPMSH_POS)



/*
 * ACC_XYZ_BAR_20_BYTE_2
 * Register Name : ACC_XYZ_BAR_20_BYTE_2
 */

/*
 * ay_cd 
 * y-axis HB sense capacitance trim
 */
#define ACC_XYZ_BAR_20_BYTE_2_AY_CD_POS      0x00
#define ACC_XYZ_BAR_20_BYTE_2_AY_CD_MASK     0x0f

/*
 * ay_cpmgnd 
 * y-axis HB AS-gnd capacitance trim
 */
#define ACC_XYZ_BAR_20_BYTE_2_AY_CPMGND_POS      0x04
#define ACC_XYZ_BAR_20_BYTE_2_AY_CPMGND_MASK     (0x0f << ACC_XYZ_BAR_20_BYTE_2_AY_CPMGND_POS)



/*
 * ACC_XYZ_BAR_20_BYTE_3
 * Register Name : ACC_XYZ_BAR_20_BYTE_3
 */

/*
 * ay_cpmsh 
 * y-axis HB AS-shield capacitance trim
 */
#define ACC_XYZ_BAR_20_BYTE_3_AY_CPMSH_POS      0x00
#define ACC_XYZ_BAR_20_BYTE_3_AY_CPMSH_MASK     0x0f

/*
 * axy_ibn 
 * xy pull-down current trimming for first stage current mismatch
 */
#define ACC_XYZ_BAR_20_BYTE_3_AXY_IBN_POS      0x04
#define ACC_XYZ_BAR_20_BYTE_3_AXY_IBN_MASK     (0x03 << ACC_XYZ_BAR_20_BYTE_3_AXY_IBN_POS)

/*
 * axy_ibp 
 * xy pull-up current trimming for first stage current mismatch
 */
#define ACC_XYZ_BAR_20_BYTE_3_AXY_IBP_POS      0x06
#define ACC_XYZ_BAR_20_BYTE_3_AXY_IBP_MASK     (0x03 << ACC_XYZ_BAR_20_BYTE_3_AXY_IBP_POS)



/*
 * ACC_XYZ_BAR_21_BYTE_0
 * Register Name : ACC_XYZ_BAR_21_BYTE_0
 */

/*
 * az_ibn 
 * z pull-down current trimming for first stage current mismatch
 */
#define ACC_XYZ_BAR_21_BYTE_0_AZ_IBN_POS      0x00
#define ACC_XYZ_BAR_21_BYTE_0_AZ_IBN_MASK     0x0f

/*
 * az_ibp 
 * z pull-up current trimming for first stage current mismatch
 */
#define ACC_XYZ_BAR_21_BYTE_0_AZ_IBP_POS      0x04
#define ACC_XYZ_BAR_21_BYTE_0_AZ_IBP_MASK     (0x0f << ACC_XYZ_BAR_21_BYTE_0_AZ_IBP_POS)



/*
 * ACC_XYZ_BAR_21_BYTE_1
 * Register Name : ACC_XYZ_BAR_21_BYTE_1
 */

/*
 * ax_cfb 
 * x-axis gain trim
 */
#define ACC_XYZ_BAR_21_BYTE_1_AX_CFB_POS      0x00
#define ACC_XYZ_BAR_21_BYTE_1_AX_CFB_MASK     0x1f

/*
 * ax_pol_drive 
 * x-axis driving polarity
 */
#define ACC_XYZ_BAR_21_BYTE_1_AX_POL_DRIVE_POS      0x05
#define ACC_XYZ_BAR_21_BYTE_1_AX_POL_DRIVE_MASK     (0x01 << ACC_XYZ_BAR_21_BYTE_1_AX_POL_DRIVE_POS)

/*
 * ay_pol_drive 
 * y-axis driving polarity
 */
#define ACC_XYZ_BAR_21_BYTE_1_AY_POL_DRIVE_POS      0x06
#define ACC_XYZ_BAR_21_BYTE_1_AY_POL_DRIVE_MASK     (0x01 << ACC_XYZ_BAR_21_BYTE_1_AY_POL_DRIVE_POS)

/*
 * az_pol_drive 
 * z-axis driving polarity
 */
#define ACC_XYZ_BAR_21_BYTE_1_AZ_POL_DRIVE_POS      0x07
#define ACC_XYZ_BAR_21_BYTE_1_AZ_POL_DRIVE_MASK     (0x01 << ACC_XYZ_BAR_21_BYTE_1_AZ_POL_DRIVE_POS)



/*
 * ACC_XYZ_BAR_21_BYTE_2
 * Register Name : ACC_XYZ_BAR_21_BYTE_2
 */

/*
 * ay_cfb 
 * y-axis gain trim
 */
#define ACC_XYZ_BAR_21_BYTE_2_AY_CFB_POS      0x00
#define ACC_XYZ_BAR_21_BYTE_2_AY_CFB_MASK     0x1f

/*
 * accel_rcm 
 * c2v first stage load resistor trim (50kOhms target)
 */
#define ACC_XYZ_BAR_21_BYTE_2_ACCEL_RCM_POS      0x05
#define ACC_XYZ_BAR_21_BYTE_2_ACCEL_RCM_MASK     (0x07 << ACC_XYZ_BAR_21_BYTE_2_ACCEL_RCM_POS)



/*
 * ACC_XYZ_BAR_21_BYTE_3
 * Register Name : ACC_XYZ_BAR_21_BYTE_3
 */

/*
 * az_cfb 
 * z-axis gain trim
 */
#define ACC_XYZ_BAR_21_BYTE_3_AZ_CFB_POS      0x00
#define ACC_XYZ_BAR_21_BYTE_3_AZ_CFB_MASK     0x1f

/*
 * accel_adc_ref 
 * nan
 */
#define ACC_XYZ_BAR_21_BYTE_3_ACCEL_ADC_REF_POS      0x05
#define ACC_XYZ_BAR_21_BYTE_3_ACCEL_ADC_REF_MASK     (0x07 << ACC_XYZ_BAR_21_BYTE_3_ACCEL_ADC_REF_POS)



/*
 * ACC_XYZ_BAR_22_BYTE_0
 * Register Name : ACC_XYZ_BAR_22_BYTE_0
 */

/*
 * accel_adc_force_chop_off 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_FORCE_CHOP_OFF_POS      0x00
#define ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_FORCE_CHOP_OFF_MASK     0x01

/*
 * accel_adc_chop_sel0 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_CHOP_SEL0_POS      0x01
#define ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_CHOP_SEL0_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_CHOP_SEL0_POS)

/*
 * accel_adc_chop_sel1 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_CHOP_SEL1_POS      0x02
#define ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_CHOP_SEL1_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_CHOP_SEL1_POS)

/*
 * accel_adc_lpf 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_LPF_POS      0x03
#define ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_LPF_MASK     (0x1f << ACC_XYZ_BAR_22_BYTE_0_ACCEL_ADC_LPF_POS)



/*
 * ACC_XYZ_BAR_22_BYTE_1
 * Register Name : ACC_XYZ_BAR_22_BYTE_1
 */

/*
 * pd_accel_adc_dig_mask 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_DIG_MASK_POS      0x00
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_DIG_MASK_MASK     0x01

/*
 * pd_accel_adc_lpf_ovr_b 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_LPF_OVR_B_POS      0x01
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_LPF_OVR_B_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_LPF_OVR_B_POS)

/*
 * pd_accel_adc_int_ovr_b 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_INT_OVR_B_POS      0x02
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_INT_OVR_B_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_INT_OVR_B_POS)

/*
 * pd_accel_adc_ref_ovr_b 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_REF_OVR_B_POS      0x03
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_REF_OVR_B_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_REF_OVR_B_POS)

/*
 * pd_accel_adc_sar_ovr_b 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_SAR_OVR_B_POS      0x04
#define ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_SAR_OVR_B_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_1_PD_ACCEL_ADC_SAR_OVR_B_POS)

/*
 * accel_adc_en_calibration 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_EN_CALIBRATION_POS      0x05
#define ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_EN_CALIBRATION_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_EN_CALIBRATION_POS)

/*
 * accel_adc_force_fbp 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_FORCE_FBP_POS      0x06
#define ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_FORCE_FBP_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_FORCE_FBP_POS)

/*
 * accel_adc_force_fbn 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_FORCE_FBN_POS      0x07
#define ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_FORCE_FBN_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_1_ACCEL_ADC_FORCE_FBN_POS)



/*
 * ACC_XYZ_BAR_22_BYTE_2
 * Register Name : ACC_XYZ_BAR_22_BYTE_2
 */

/*
 * accel_adc_force_fbno 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_ADC_FORCE_FBNO_POS      0x00
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_ADC_FORCE_FBNO_MASK     0x01

/*
 * accel_c2v_rr_axis_ovrd 
 * defines which axis to be monitored-
 * 2'b00: all (default)
 * 2'b01: x, 2'b10:y, 2'b11:z
 */
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_RR_AXIS_OVRD_POS      0x01
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_RR_AXIS_OVRD_MASK     (0x03 << ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_RR_AXIS_OVRD_POS)

/*
 * accel_c2v_gband_dis 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_GBAND_DIS_POS      0x03
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_GBAND_DIS_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_GBAND_DIS_POS)

/*
 * accel_c2v_as_gap_test 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_AS_GAP_TEST_POS      0x04
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_AS_GAP_TEST_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_AS_GAP_TEST_POS)

/*
 * accel_c2v_cp3v_always_on 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_CP3V_ALWAYS_ON_POS      0x05
#define ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_CP3V_ALWAYS_ON_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_2_ACCEL_C2V_CP3V_ALWAYS_ON_POS)

/*
 * pd_accel_c2v_b 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_2_PD_ACCEL_C2V_B_POS      0x06
#define ACC_XYZ_BAR_22_BYTE_2_PD_ACCEL_C2V_B_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_2_PD_ACCEL_C2V_B_POS)

/*
 * rst_accel_b 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_2_RST_ACCEL_B_POS      0x07
#define ACC_XYZ_BAR_22_BYTE_2_RST_ACCEL_B_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_2_RST_ACCEL_B_POS)



/*
 * ACC_XYZ_BAR_22_BYTE_3
 * Register Name : ACC_XYZ_BAR_22_BYTE_3
 */

/*
 * accel_adc_tm_cal_en 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_3_ACCEL_ADC_TM_CAL_EN_POS      0x00
#define ACC_XYZ_BAR_22_BYTE_3_ACCEL_ADC_TM_CAL_EN_MASK     0x01

/*
 * accel_c2v_refclock_select 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_3_ACCEL_C2V_REFCLOCK_SELECT_POS      0x01
#define ACC_XYZ_BAR_22_BYTE_3_ACCEL_C2V_REFCLOCK_SELECT_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_3_ACCEL_C2V_REFCLOCK_SELECT_POS)

/*
 * accel_adc_tstbuf_in_en 
 * if 1, connects test buffer output to ADC input
 */
#define ACC_XYZ_BAR_22_BYTE_3_ACCEL_ADC_TSTBUF_IN_EN_POS      0x02
#define ACC_XYZ_BAR_22_BYTE_3_ACCEL_ADC_TSTBUF_IN_EN_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_3_ACCEL_ADC_TSTBUF_IN_EN_POS)

/*
 * ax_aaf_ovr_out 
 * if 1, forces out in Hi-Z
 */
#define ACC_XYZ_BAR_22_BYTE_3_AX_AAF_OVR_OUT_POS      0x03
#define ACC_XYZ_BAR_22_BYTE_3_AX_AAF_OVR_OUT_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_3_AX_AAF_OVR_OUT_POS)

/*
 * ay_aaf_ovr_out 
 * if 1, forces out in Hi-Z
 */
#define ACC_XYZ_BAR_22_BYTE_3_AY_AAF_OVR_OUT_POS      0x04
#define ACC_XYZ_BAR_22_BYTE_3_AY_AAF_OVR_OUT_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_3_AY_AAF_OVR_OUT_POS)

/*
 * az_aaf_ovr_out 
 * if 1, forces out in Hi-Z
 */
#define ACC_XYZ_BAR_22_BYTE_3_AZ_AAF_OVR_OUT_POS      0x05
#define ACC_XYZ_BAR_22_BYTE_3_AZ_AAF_OVR_OUT_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_3_AZ_AAF_OVR_OUT_POS)

/*
 * azsh2tb_en 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_3_AZSH2TB_EN_POS      0x06
#define ACC_XYZ_BAR_22_BYTE_3_AZSH2TB_EN_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_3_AZSH2TB_EN_POS)

/*
 * vsh2tb_en 
 * nan
 */
#define ACC_XYZ_BAR_22_BYTE_3_VSH2TB_EN_POS      0x07
#define ACC_XYZ_BAR_22_BYTE_3_VSH2TB_EN_MASK     (0x01 << ACC_XYZ_BAR_22_BYTE_3_VSH2TB_EN_POS)



/*
 * ACC_XYZ_BAR_23_BYTE_0
 * Register Name : ACC_XYZ_BAR_23_BYTE_0
 */

/*
 * accel_testmode 
 * testmodes enabling signals for all axis
 */
#define ACC_XYZ_BAR_23_BYTE_0_ACCEL_TESTMODE_POS      0x00
#define ACC_XYZ_BAR_23_BYTE_0_ACCEL_TESTMODE_MASK     0xff



/*
 * ACC_XYZ_BAR_23_BYTE_1
 * Register Name : ACC_XYZ_BAR_23_BYTE_1
 */

/*
 * accel_testmode 
 * testmodes enabling signals for all axis
 */
#define ACC_XYZ_BAR_23_BYTE_1_ACCEL_TESTMODE_POS      0x00
#define ACC_XYZ_BAR_23_BYTE_1_ACCEL_TESTMODE_MASK     0xff



/*
 * ACC_XYZ_BAR_23_BYTE_2
 * Register Name : ACC_XYZ_BAR_23_BYTE_2
 */

/*
 * ax_aaf_sample_dis 
 * nan
 */
#define ACC_XYZ_BAR_23_BYTE_2_AX_AAF_SAMPLE_DIS_POS      0x00
#define ACC_XYZ_BAR_23_BYTE_2_AX_AAF_SAMPLE_DIS_MASK     0x01

/*
 * ay_aaf_sample_dis 
 * nan
 */
#define ACC_XYZ_BAR_23_BYTE_2_AY_AAF_SAMPLE_DIS_POS      0x01
#define ACC_XYZ_BAR_23_BYTE_2_AY_AAF_SAMPLE_DIS_MASK     (0x01 << ACC_XYZ_BAR_23_BYTE_2_AY_AAF_SAMPLE_DIS_POS)

/*
 * az_aaf_sample_dis 
 * nan
 */
#define ACC_XYZ_BAR_23_BYTE_2_AZ_AAF_SAMPLE_DIS_POS      0x02
#define ACC_XYZ_BAR_23_BYTE_2_AZ_AAF_SAMPLE_DIS_MASK     (0x01 << ACC_XYZ_BAR_23_BYTE_2_AZ_AAF_SAMPLE_DIS_POS)

/*
 * accel_aaf_sample_dis_mask 
 * nan
 */
#define ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_SAMPLE_DIS_MASK_POS      0x03
#define ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_SAMPLE_DIS_MASK_MASK     (0x01 << ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_SAMPLE_DIS_MASK_POS)

/*
 * pd_accel_aaf_b 
 * nan
 */
#define ACC_XYZ_BAR_23_BYTE_2_PD_ACCEL_AAF_B_POS      0x04
#define ACC_XYZ_BAR_23_BYTE_2_PD_ACCEL_AAF_B_MASK     (0x01 << ACC_XYZ_BAR_23_BYTE_2_PD_ACCEL_AAF_B_POS)

/*
 * accel_aaf_chop_dis 
 * nan
 */
#define ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_CHOP_DIS_POS      0x05
#define ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_CHOP_DIS_MASK     (0x01 << ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_CHOP_DIS_POS)

/*
 * accel_aaf_mask_out 
 * enables override modes (*_aaf_ovr_out)
 */
#define ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_MASK_OUT_POS      0x06
#define ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_MASK_OUT_MASK     (0x01 << ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_MASK_OUT_POS)

/*
 * accel_aaf_chop_4p8k_dis 
 * spare bits
 */
#define ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_CHOP_4P8K_DIS_POS      0x07
#define ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_CHOP_4P8K_DIS_MASK     (0x01 << ACC_XYZ_BAR_23_BYTE_2_ACCEL_AAF_CHOP_4P8K_DIS_POS)



/*
 * ACC_XYZ_BAR_23_BYTE_3
 * Register Name : ACC_XYZ_BAR_23_BYTE_3
 */

/*
 * accel_aaf_r 
 * nan
 */
#define ACC_XYZ_BAR_23_BYTE_3_ACCEL_AAF_R_POS      0x00
#define ACC_XYZ_BAR_23_BYTE_3_ACCEL_AAF_R_MASK     0x0f

/*
 * accel_aaf_c 
 * spare bits
 */
#define ACC_XYZ_BAR_23_BYTE_3_ACCEL_AAF_C_POS      0x04
#define ACC_XYZ_BAR_23_BYTE_3_ACCEL_AAF_C_MASK     (0x0f << ACC_XYZ_BAR_23_BYTE_3_ACCEL_AAF_C_POS)



/*
 * DMD_GCT_BAR_24_BYTE_0
 * Register Name : DMD_GCT_BAR_24_BYTE_0
 */

/*
 * gyro_dmd_xpunct 
 * Demodulator fine phase for X axis
 */
#define DMD_GCT_BAR_24_BYTE_0_GYRO_DMD_XPUNCT_POS      0x00
#define DMD_GCT_BAR_24_BYTE_0_GYRO_DMD_XPUNCT_MASK     0x7f

/*
 * gyro_dmd_otp_spare 
 * spare trim bit
 */
#define DMD_GCT_BAR_24_BYTE_0_GYRO_DMD_OTP_SPARE_POS      0x07
#define DMD_GCT_BAR_24_BYTE_0_GYRO_DMD_OTP_SPARE_MASK     (0x01 << DMD_GCT_BAR_24_BYTE_0_GYRO_DMD_OTP_SPARE_POS)



/*
 * DMD_GCT_BAR_24_BYTE_1
 * Register Name : DMD_GCT_BAR_24_BYTE_1
 */

/*
 * gyro_dmd_pol_inv 
 * invert mixer polarity
 */
#define DMD_GCT_BAR_24_BYTE_1_GYRO_DMD_POL_INV_POS      0x07
#define DMD_GCT_BAR_24_BYTE_1_GYRO_DMD_POL_INV_MASK     (0x01 << DMD_GCT_BAR_24_BYTE_1_GYRO_DMD_POL_INV_POS)

/*
 * gyro_dmd_ypunct 
 * Demodulator fine phase for Y axis
 */
#define DMD_GCT_BAR_24_BYTE_1_GYRO_DMD_YPUNCT_POS      0x00
#define DMD_GCT_BAR_24_BYTE_1_GYRO_DMD_YPUNCT_MASK     0x7f



/*
 * DMD_GCT_BAR_24_BYTE_2
 * Register Name : DMD_GCT_BAR_24_BYTE_2
 */

/*
 * gyro_dmd_chop_15k_en 
 * enable adc 15k choppper
 */
#define DMD_GCT_BAR_24_BYTE_2_GYRO_DMD_CHOP_15K_EN_POS      0x07
#define DMD_GCT_BAR_24_BYTE_2_GYRO_DMD_CHOP_15K_EN_MASK     (0x01 << DMD_GCT_BAR_24_BYTE_2_GYRO_DMD_CHOP_15K_EN_POS)

/*
 * gyro_dmd_zpunct 
 * Demodulator fine phase for Z axis
 */
#define DMD_GCT_BAR_24_BYTE_2_GYRO_DMD_ZPUNCT_POS      0x00
#define DMD_GCT_BAR_24_BYTE_2_GYRO_DMD_ZPUNCT_MASK     0x7f



/*
 * DMD_GCT_BAR_24_BYTE_3
 * Register Name : DMD_GCT_BAR_24_BYTE_3
 */

/*
 * gyro_dmd_nfbdel 
 * demodulator delay respect to pll fb clk
 */
#define DMD_GCT_BAR_24_BYTE_3_GYRO_DMD_NFBDEL_POS      0x00
#define DMD_GCT_BAR_24_BYTE_3_GYRO_DMD_NFBDEL_MASK     0xff



/*
 * DMD_GCT_BAR_25_BYTE_0
 * Register Name : DMD_GCT_BAR_25_BYTE_0
 */

/*
 * gyro_adc_aaf_freq 
 * aaf cut off frequency trim
 */
#define DMD_GCT_BAR_25_BYTE_0_GYRO_ADC_AAF_FREQ_POS      0x03
#define DMD_GCT_BAR_25_BYTE_0_GYRO_ADC_AAF_FREQ_MASK     (0x1f << DMD_GCT_BAR_25_BYTE_0_GYRO_ADC_AAF_FREQ_POS)

/*
 * gyro_dmd_nduty 
 * Demodulator count (derived from pll divider)
 */
#define DMD_GCT_BAR_25_BYTE_0_GYRO_DMD_NDUTY_POS      0x00
#define DMD_GCT_BAR_25_BYTE_0_GYRO_DMD_NDUTY_MASK     0x07



/*
 * DMD_GCT_BAR_25_BYTE_1
 * Register Name : DMD_GCT_BAR_25_BYTE_1
 */

/*
 * gyro_adc_chop_aaf_en 
 * enable aaf chopper
 */
#define DMD_GCT_BAR_25_BYTE_1_GYRO_ADC_CHOP_AAF_EN_POS      0x07
#define DMD_GCT_BAR_25_BYTE_1_GYRO_ADC_CHOP_AAF_EN_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_1_GYRO_ADC_CHOP_AAF_EN_POS)

/*
 * gyro_adc_chop_int_en 
 * enable  sd integrator chopper
 */
#define DMD_GCT_BAR_25_BYTE_1_GYRO_ADC_CHOP_INT_EN_POS      0x06
#define DMD_GCT_BAR_25_BYTE_1_GYRO_ADC_CHOP_INT_EN_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_1_GYRO_ADC_CHOP_INT_EN_POS)

/*
 * gyro_dmd_xph 
 * Demodulator phase for X axis, respect to fbclk
 */
#define DMD_GCT_BAR_25_BYTE_1_GYRO_DMD_XPH_POS      0x03
#define DMD_GCT_BAR_25_BYTE_1_GYRO_DMD_XPH_MASK     (0x07 << DMD_GCT_BAR_25_BYTE_1_GYRO_DMD_XPH_POS)

/*
 * gyro_dmd_yph 
 * Demodulator phase for Y axis, respect to fbclk
 */
#define DMD_GCT_BAR_25_BYTE_1_GYRO_DMD_YPH_POS      0x00
#define DMD_GCT_BAR_25_BYTE_1_GYRO_DMD_YPH_MASK     0x07



/*
 * DMD_GCT_BAR_25_BYTE_2
 * Register Name : DMD_GCT_BAR_25_BYTE_2
 */

/*
 * gyro_dmd_ninit_adj 
 * Demodulator initial dead zone
 */
#define DMD_GCT_BAR_25_BYTE_2_GYRO_DMD_NINIT_ADJ_POS      0x03
#define DMD_GCT_BAR_25_BYTE_2_GYRO_DMD_NINIT_ADJ_MASK     (0x03 << DMD_GCT_BAR_25_BYTE_2_GYRO_DMD_NINIT_ADJ_POS)

/*
 * gyro_dmd_zph 
 * Demodulator phase for Z axis, respect to fbclk
 */
#define DMD_GCT_BAR_25_BYTE_2_GYRO_DMD_ZPH_POS      0x00
#define DMD_GCT_BAR_25_BYTE_2_GYRO_DMD_ZPH_MASK     0x07

/*
 * gyro_dmd_otp_spare 
 * spare trim bit
 */
#define DMD_GCT_BAR_25_BYTE_2_GYRO_DMD_OTP_SPARE_POS      0x05
#define DMD_GCT_BAR_25_BYTE_2_GYRO_DMD_OTP_SPARE_MASK     (0x07 << DMD_GCT_BAR_25_BYTE_2_GYRO_DMD_OTP_SPARE_POS)



/*
 * DMD_GCT_BAR_25_BYTE_3
 * Register Name : DMD_GCT_BAR_25_BYTE_3
 */

/*
 * gyro_adc_tm_cal_n 
 * adc calibration negative fold
 */
#define DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_N_POS      0x07
#define DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_N_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_N_POS)

/*
 * gyro_adc_tm_cal_no 
 * adc calibration no fold
 */
#define DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_NO_POS      0x06
#define DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_NO_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_NO_POS)

/*
 * gyro_adc_tm_cal_p 
 * adc calibration positive fold
 */
#define DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_P_POS      0x05
#define DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_P_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_P_POS)

/*
 * gyro_adc_tm_cal_en 
 * adc calibration enable
 */
#define DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_EN_POS      0x04
#define DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_EN_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_3_GYRO_ADC_TM_CAL_EN_POS)

/*
 * gyro_dmd_ana_mixer_hold 
 * override active low mixer power down
 */
#define DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_ANA_MIXER_HOLD_POS      0x03
#define DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_ANA_MIXER_HOLD_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_ANA_MIXER_HOLD_POS)

/*
 * gyro_dmd_mixer_out_hiz 
 * force mixer out hiz
 */
#define DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_MIXER_OUT_HIZ_POS      0x02
#define DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_MIXER_OUT_HIZ_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_MIXER_OUT_HIZ_POS)

/*
 * gyro_dmd_intg_on 
 * enable demodulator integrator phase
 */
#define DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_INTG_ON_POS      0x01
#define DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_INTG_ON_MASK     (0x01 << DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_INTG_ON_POS)

/*
 * gyro_dmd_mixer_in_short 
 * short mixer output to vcm
 */
#define DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_MIXER_IN_SHORT_POS      0x00
#define DMD_GCT_BAR_25_BYTE_3_GYRO_DMD_MIXER_IN_SHORT_MASK     0x01



/*
 * DMD_GCT_BAR_26_BYTE_0
 * Register Name : DMD_GCT_BAR_26_BYTE_0
 */

/*
 * pd_gyro_dmd_ovrd_b 
 * override active low demodulator power down
 */
#define DMD_GCT_BAR_26_BYTE_0_PD_GYRO_DMD_OVRD_B_POS      0x07
#define DMD_GCT_BAR_26_BYTE_0_PD_GYRO_DMD_OVRD_B_MASK     (0x01 << DMD_GCT_BAR_26_BYTE_0_PD_GYRO_DMD_OVRD_B_POS)

/*
 * pd_gyro_adc_ovrd_b 
 * adc power down override
 */
#define DMD_GCT_BAR_26_BYTE_0_PD_GYRO_ADC_OVRD_B_POS      0x06
#define DMD_GCT_BAR_26_BYTE_0_PD_GYRO_ADC_OVRD_B_MASK     (0x01 << DMD_GCT_BAR_26_BYTE_0_PD_GYRO_ADC_OVRD_B_POS)

/*
 * pd_gyro_adc_ref_ovrd 
 * adc reference power down override
 */
#define DMD_GCT_BAR_26_BYTE_0_PD_GYRO_ADC_REF_OVRD_POS      0x05
#define DMD_GCT_BAR_26_BYTE_0_PD_GYRO_ADC_REF_OVRD_MASK     (0x01 << DMD_GCT_BAR_26_BYTE_0_PD_GYRO_ADC_REF_OVRD_POS)

/*
 * gyro_dmd_cfg_spare1 
 * demodulator configuration spare
 */
#define DMD_GCT_BAR_26_BYTE_0_GYRO_DMD_CFG_SPARE1_POS      0x03
#define DMD_GCT_BAR_26_BYTE_0_GYRO_DMD_CFG_SPARE1_MASK     (0x03 << DMD_GCT_BAR_26_BYTE_0_GYRO_DMD_CFG_SPARE1_POS)

/*
 * gyro_dmd_cfg_spare 
 * nan
 */
#define DMD_GCT_BAR_26_BYTE_0_GYRO_DMD_CFG_SPARE_POS      0x00
#define DMD_GCT_BAR_26_BYTE_0_GYRO_DMD_CFG_SPARE_MASK     0x07



/*
 * DMD_GCT_BAR_26_BYTE_1
 * Register Name : DMD_GCT_BAR_26_BYTE_1
 */

/*
 * gyro_dmd_cfg_spare1 
 * demodulator configuration spare
 */
#define DMD_GCT_BAR_26_BYTE_1_GYRO_DMD_CFG_SPARE1_POS      0x00
#define DMD_GCT_BAR_26_BYTE_1_GYRO_DMD_CFG_SPARE1_MASK     0x07

/*
 * gyro_sar_tm_en 
 * nan
 */
#define DMD_GCT_BAR_26_BYTE_1_GYRO_SAR_TM_EN_POS      0x07
#define DMD_GCT_BAR_26_BYTE_1_GYRO_SAR_TM_EN_MASK     (0x01 << DMD_GCT_BAR_26_BYTE_1_GYRO_SAR_TM_EN_POS)

/*
 * pd_adc_ref_ovrd_b 
 * nan
 */
#define DMD_GCT_BAR_26_BYTE_1_PD_ADC_REF_OVRD_B_POS      0x06
#define DMD_GCT_BAR_26_BYTE_1_PD_ADC_REF_OVRD_B_MASK     (0x01 << DMD_GCT_BAR_26_BYTE_1_PD_ADC_REF_OVRD_B_POS)

/*
 * pd_sd_comp_ovrd_b 
 * nan
 */
#define DMD_GCT_BAR_26_BYTE_1_PD_SD_COMP_OVRD_B_POS      0x05
#define DMD_GCT_BAR_26_BYTE_1_PD_SD_COMP_OVRD_B_MASK     (0x01 << DMD_GCT_BAR_26_BYTE_1_PD_SD_COMP_OVRD_B_POS)

/*
 * pd_sd_int_ovrd_b 
 * nan
 */
#define DMD_GCT_BAR_26_BYTE_1_PD_SD_INT_OVRD_B_POS      0x04
#define DMD_GCT_BAR_26_BYTE_1_PD_SD_INT_OVRD_B_MASK     (0x01 << DMD_GCT_BAR_26_BYTE_1_PD_SD_INT_OVRD_B_POS)

/*
 * pd_sd_lpf_ovrd_b 
 * nan
 */
#define DMD_GCT_BAR_26_BYTE_1_PD_SD_LPF_OVRD_B_POS      0x03
#define DMD_GCT_BAR_26_BYTE_1_PD_SD_LPF_OVRD_B_MASK     (0x01 << DMD_GCT_BAR_26_BYTE_1_PD_SD_LPF_OVRD_B_POS)



/*
 * DMD_GCT_BAR_26_BYTE_2
 * Register Name : DMD_GCT_BAR_26_BYTE_2
 */

/*
 * gyro_adc_tm_mux_sel 
 * nan
 */
#define DMD_GCT_BAR_26_BYTE_2_GYRO_ADC_TM_MUX_SEL_POS      0x00
#define DMD_GCT_BAR_26_BYTE_2_GYRO_ADC_TM_MUX_SEL_MASK     0xff



/*
 * DMD_GCT_BAR_26_BYTE_3
 * Register Name : DMD_GCT_BAR_26_BYTE_3
 */

/*
 * gyro_dmd_cfg_spare1 
 * demodulator configuration spare
 */
#define DMD_GCT_BAR_26_BYTE_3_GYRO_DMD_CFG_SPARE1_POS      0x06
#define DMD_GCT_BAR_26_BYTE_3_GYRO_DMD_CFG_SPARE1_MASK     (0x03 << DMD_GCT_BAR_26_BYTE_3_GYRO_DMD_CFG_SPARE1_POS)

/*
 * gyro_adc_tm_mux_sel 
 * nan
 */
#define DMD_GCT_BAR_26_BYTE_3_GYRO_ADC_TM_MUX_SEL_POS      0x00
#define DMD_GCT_BAR_26_BYTE_3_GYRO_ADC_TM_MUX_SEL_MASK     0x3f



/*
 * DRV_GYR_BAR_27_BYTE_0
 * Register Name : DRV_GYR_BAR_27_BYTE_0
 */

/*
 * gyro_drv_agc_amp 
 * Drive amplitude setting …. Add trimming table
 */
#define DRV_GYR_BAR_27_BYTE_0_GYRO_DRV_AGC_AMP_POS      0x04
#define DRV_GYR_BAR_27_BYTE_0_GYRO_DRV_AGC_AMP_MASK     (0x0f << DRV_GYR_BAR_27_BYTE_0_GYRO_DRV_AGC_AMP_POS)

/*
 * gyro_drv_agc_gain 
 * AGC loop gain trim (V2I gain)
 */
#define DRV_GYR_BAR_27_BYTE_0_GYRO_DRV_AGC_GAIN_POS      0x00
#define DRV_GYR_BAR_27_BYTE_0_GYRO_DRV_AGC_GAIN_MASK     0x0f



/*
 * DRV_GYR_BAR_27_BYTE_1
 * Register Name : DRV_GYR_BAR_27_BYTE_1
 */

/*
 * gyro_drv_chop_clk_sel 
 * Drive AGC integrator chopper clock configuration and clock synchronization …. Add selection table
 */
#define DRV_GYR_BAR_27_BYTE_1_GYRO_DRV_CHOP_CLK_SEL_POS      0x04
#define DRV_GYR_BAR_27_BYTE_1_GYRO_DRV_CHOP_CLK_SEL_MASK     (0x0f << DRV_GYR_BAR_27_BYTE_1_GYRO_DRV_CHOP_CLK_SEL_POS)

/*
 * gyro_drv_agc_lp 
 * AGC PI low pass trimming
 */
#define DRV_GYR_BAR_27_BYTE_1_GYRO_DRV_AGC_LP_POS      0x00
#define DRV_GYR_BAR_27_BYTE_1_GYRO_DRV_AGC_LP_MASK     0x0f



/*
 * DRV_GYR_BAR_27_BYTE_2
 * Register Name : DRV_GYR_BAR_27_BYTE_2
 */

/*
 * gyro_drv_chp_clk_sel 
 * Select charge pumps switching frequency, add selection table, specify bit 7 and 6
 * 7: 0 … / 1…
 * 6: 0 … / 1…
 * 5,4: 00 … / 01 … / 10 … / 11 …
 * 3,2: 00 … / 01 … / 10 … / 11 …
 * 1,0: 00 … / 01 … / 10 … / 11 ...
 */
#define DRV_GYR_BAR_27_BYTE_2_GYRO_DRV_CHP_CLK_SEL_POS      0x00
#define DRV_GYR_BAR_27_BYTE_2_GYRO_DRV_CHP_CLK_SEL_MASK     0xff



/*
 * DRV_GYR_BAR_27_BYTE_3
 * Register Name : DRV_GYR_BAR_27_BYTE_3
 */

/*
 * gyro_drv_phs_swap_polarity 
 * Swap phase shifter polarity
 */
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_PHS_SWAP_POLARITY_POS      0x07
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_PHS_SWAP_POLARITY_MASK     (0x01 << DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_PHS_SWAP_POLARITY_POS)

/*
 * gyro_drv_hvd_swap_polarity 
 * Swap high voltage drive polatiry …Nome da correggre suglis chemi...
 */
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_HVD_SWAP_POLARITY_POS      0x06
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_HVD_SWAP_POLARITY_MASK     (0x01 << DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_HVD_SWAP_POLARITY_POS)

/*
 * gyro_drv_phs_source_sel 
 * Drive steady state phase shifter source selecgtor: 1 phase shifter signal generated from PLL, 0 from analog circuit
 */
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_PHS_SOURCE_SEL_POS      0x00
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_PHS_SOURCE_SEL_MASK     0x01

/*
 * gyro_drv_agc_chop_disable 
 * Disable drive agc integrator choppper
 */
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_AGC_CHOP_DISABLE_POS      0x04
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_AGC_CHOP_DISABLE_MASK     (0x01 << DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_AGC_CHOP_DISABLE_POS)

/*
 * gyro_drv_prech_threshold_340m 
 * Control loop filter precharge level selector:
 * 0: 370mVp
 * 1: 340mVp
 */
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_PRECH_THRESHOLD_340M_POS      0x05
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_PRECH_THRESHOLD_340M_MASK     (0x01 << DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_PRECH_THRESHOLD_340M_POS)

/*
 * gyro_drv_xst_pol 
 * X self test polarity selection: …. Description ….
 */
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_XST_POL_POS      0x03
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_XST_POL_MASK     (0x01 << DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_XST_POL_POS)

/*
 * gyro_drv_yst_pol 
 * Y self test polarity selection: …. Description ….
 */
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_YST_POL_POS      0x02
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_YST_POL_MASK     (0x01 << DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_YST_POL_POS)

/*
 * gyro_drv_zst_pol 
 * Z self test polarity selection: …. Description ….
 */
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_ZST_POL_POS      0x01
#define DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_ZST_POL_MASK     (0x01 << DRV_GYR_BAR_27_BYTE_3_GYRO_DRV_ZST_POL_POS)



/*
 * DRV_GYR_BAR_28_BYTE_0
 * Register Name : DRV_GYR_BAR_28_BYTE_0
 */

/*
 * gyro_drv_phs_gain_cm 
 * Phase shifter start-up V2I: common mode gain trim
 */
#define DRV_GYR_BAR_28_BYTE_0_GYRO_DRV_PHS_GAIN_CM_POS      0x05
#define DRV_GYR_BAR_28_BYTE_0_GYRO_DRV_PHS_GAIN_CM_MASK     (0x07 << DRV_GYR_BAR_28_BYTE_0_GYRO_DRV_PHS_GAIN_CM_POS)

/*
 * gyro_drv_phs_gain_diff 
 * Phase shifter start-up V2I: differential mode gain trim … add trimming table
 */
#define DRV_GYR_BAR_28_BYTE_0_GYRO_DRV_PHS_GAIN_DIFF_POS      0x02
#define DRV_GYR_BAR_28_BYTE_0_GYRO_DRV_PHS_GAIN_DIFF_MASK     (0x07 << DRV_GYR_BAR_28_BYTE_0_GYRO_DRV_PHS_GAIN_DIFF_POS)

/*
 * gyro_drv_oscmon_timeout 
 * nan
 */
#define DRV_GYR_BAR_28_BYTE_0_GYRO_DRV_OSCMON_TIMEOUT_POS      0x00
#define DRV_GYR_BAR_28_BYTE_0_GYRO_DRV_OSCMON_TIMEOUT_MASK     0x03



/*
 * DRV_GYR_BAR_28_BYTE_1
 * Register Name : DRV_GYR_BAR_28_BYTE_1
 */

/*
 * gyro_drv_spare_otp 
 * Reserved
 */
#define DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_SPARE_OTP_POS      0x02
#define DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_SPARE_OTP_MASK     (0x03 << DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_SPARE_OTP_POS)

/*
 * gyro_drv_phs_freq 
 * Phase shifter pole frequency … add trimming table …
 */
#define DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_PHS_FREQ_POS      0x05
#define DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_PHS_FREQ_MASK     (0x07 << DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_PHS_FREQ_POS)

/*
 * gyro_drv_oscmon_window 
 * nan
 */
#define DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_OSCMON_WINDOW_POS      0x00
#define DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_OSCMON_WINDOW_MASK     0x03

/*
 * gyro_drv_st_clk_sel 
 * nan
 */
#define DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_ST_CLK_SEL_POS      0x04
#define DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_ST_CLK_SEL_MASK     (0x01 << DRV_GYR_BAR_28_BYTE_1_GYRO_DRV_ST_CLK_SEL_POS)



/*
 * DRV_GYR_BAR_29_BYTE_0
 * Register Name : DRV_GYR_BAR_29_BYTE_0
 */

/*
 * gyro_drv_tm_selst 
 * Configure gyro self test with external input  clock from DTP3
 */
#define DRV_GYR_BAR_29_BYTE_0_GYRO_DRV_TM_SELST_POS      0x00
#define DRV_GYR_BAR_29_BYTE_0_GYRO_DRV_TM_SELST_MASK     0x01

/*
 * gyro_drv_tm_loopfilter 
 * Control loop filter test/debug
 * 6: HV Driver Feedback Amp Reference Input  (for voltage forcing purposes) on ATP2
 * 5: HV Driver Feedback Amp Reference Input  (for voltage sensing purposes) on ATP0
 * 4: AGC Integrator Output v2i forcing on ATP2
 * 3: HV Driver Feedback Amp Reference Input DC Value proxy /AGC Integrator Output (both for voltage sensing purposes) on ATP0, ATP1 respectively
 * 2: N/A
 * 1: Sense AGC output current
 * 0: AGC Integrator Output v2i forcing on ATP0
 */
#define DRV_GYR_BAR_29_BYTE_0_GYRO_DRV_TM_LOOPFILTER_POS      0x01
#define DRV_GYR_BAR_29_BYTE_0_GYRO_DRV_TM_LOOPFILTER_MASK     (0x7f << DRV_GYR_BAR_29_BYTE_0_GYRO_DRV_TM_LOOPFILTER_POS)



/*
 * DRV_GYR_BAR_29_BYTE_1
 * Register Name : DRV_GYR_BAR_29_BYTE_1
 */

/*
 * gyro_drv_tm_phs 
 * Phase shifter debug
 * 2: Phase Shifter Linear Stage Input on ATP0, ATP1
 * 1: Phase 2nd Stage (differential) on ATP0, ATP1
 * 0: Phase Shifter Buffer (differential) on ATP0, ATP1
 */
#define DRV_GYR_BAR_29_BYTE_1_GYRO_DRV_TM_PHS_POS      0x00
#define DRV_GYR_BAR_29_BYTE_1_GYRO_DRV_TM_PHS_MASK     0x07

/*
 * gyro_drv_tm_hvd_acmux 
 * High voltage driver AC output multiplexer control bit
 * 3: AC Coupled Test Mode Enable: dp_div15, dn_div15 on ATP0, ATP1  (...for loop back check)
 * 2: AC Coupled Test Mode for dp_div15 on ATP3
 * 1: AC Coupled Test Mode for dn_div15 on ATP3
 * 0: AC Coupled Test Mode Enable: dp_div15, dn_div15 on ATP2, ATP3
 */
#define DRV_GYR_BAR_29_BYTE_1_GYRO_DRV_TM_HVD_ACMUX_POS      0x03
#define DRV_GYR_BAR_29_BYTE_1_GYRO_DRV_TM_HVD_ACMUX_MASK     (0x0f << DRV_GYR_BAR_29_BYTE_1_GYRO_DRV_TM_HVD_ACMUX_POS)

/*
 * gyro_drv_tm_pllref_agcon 
 * PLLrefReady/AGCon routed on DTP0, DTP1
 */
#define DRV_GYR_BAR_29_BYTE_1_GYRO_DRV_TM_PLLREF_AGCON_POS      0x07
#define DRV_GYR_BAR_29_BYTE_1_GYRO_DRV_TM_PLLREF_AGCON_MASK     (0x01 << DRV_GYR_BAR_29_BYTE_1_GYRO_DRV_TM_PLLREF_AGCON_POS)



/*
 * DRV_GYR_BAR_29_BYTE_2
 * Register Name : DRV_GYR_BAR_29_BYTE_2
 */

/*
 * gyro_drv_tm_chp 
 * Drive charge pump system test/debug proxy
 * 3: 6V self test charge pump proxy (divided down 24*Vtp) on ATP3
 * 2: -3V charge pump proxy (divided down: 3*Vtp-2*avdd) on ATP0
 * 1: 3V charge pump proxy (divided down 6*Vtp) on ATP1
 * 0: 6V charge pump proxy (divided down 6*Vtp) onATP2
 */
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_CHP_POS      0x04
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_CHP_MASK     (0x0f << DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_CHP_POS)

/*
 * gyro_drv_tm_dmd_comp_ref 
 * Dcc Loop 0.7V reference on ATP0
 */
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_DMD_COMP_REF_POS      0x00
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_DMD_COMP_REF_MASK     0x01

/*
 * gyro_drv_tm_phscompdeg_stclk 
 * ST clock / Phase Shifter Comparator Output sniff on DTP0 and DTP2
 */
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_PHSCOMPDEG_STCLK_POS      0x01
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_PHSCOMPDEG_STCLK_MASK     (0x01 << DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_PHSCOMPDEG_STCLK_POS)

/*
 * gyro_drv_tm_oscmon_prchcomp 
 * Oscillator Monitor Comparator/Precharge Comparator/ Oscillator monitor window sniff  on DTP0, DTP1 and DTP2 respectively
 */
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_OSCMON_PRCHCOMP_POS      0x02
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_OSCMON_PRCHCOMP_MASK     (0x01 << DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_OSCMON_PRCHCOMP_POS)

/*
 * gyro_drv_tm_pll_ref_clk 
 * Pll Reference Clock sniff on DTP3
 */
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_PLL_REF_CLK_POS      0x03
#define DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_PLL_REF_CLK_MASK     (0x01 << DRV_GYR_BAR_29_BYTE_2_GYRO_DRV_TM_PLL_REF_CLK_POS)



/*
 * DRV_GYR_BAR_29_BYTE_3
 * Register Name : DRV_GYR_BAR_29_BYTE_3
 */

/*
 * gyro_drv_xst_mode 
 * X self test mode selection:
 * 00: ST P/N electrodes driven differentially
 * 01: ST P electrode set to "low" & N electrode only is driven with the ST input signal
 * 10: ST N electrode set to "low" & P electrode only is driven with the ST input signal
 * 11: ST P/N electrodes driven with same polarity (both high or both low), according to the ST input signal
 */
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_XST_MODE_POS      0x00
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_XST_MODE_MASK     0x03

/*
 * gyro_drv_yst_mode 
 * Y self test mode selection:
 * 00: ST P/N electrodes driven differentially 
 * 01: ST P electrode set to "low" & N electrode only is driven with the ST input signal
 * 10: ST N electrode set to "low" & P electrode only is driven with the ST input signal
 * 11: ST P/N electrodes driven with same polarity (both high or both low), according to the ST input signal
 */
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_YST_MODE_POS      0x02
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_YST_MODE_MASK     (0x03 << DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_YST_MODE_POS)

/*
 * gyro_drv_zst_mode 
 * Z self test mode selection:
 * 00: ST P/N electrodes driven differentially 
 * 01: ST P electrode set to "low" & N electrode only is driven with the ST input signal
 * 10: ST N electrode set to "low" & P electrode only is driven with the ST input signal
 * 11: ST P/N electrodes driven with same polarity (both high or both low), according to the ST input signal
 */
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_ZST_MODE_POS      0x04
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_ZST_MODE_MASK     (0x03 << DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_ZST_MODE_POS)

/*
 * gyro_drv_oscdetector_disable 
 * Bypass oscillator monitor
 */
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_OSCDETECTOR_DISABLE_POS      0x07
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_OSCDETECTOR_DISABLE_MASK     (0x01 << DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_OSCDETECTOR_DISABLE_POS)

/*
 * gyro_drv_en_dcc_tm 
 * DRV IP duty-cycle correction test enable. 1: forces en_gyro_drv_dcc_d2a=1, 0: en_gyro_drv_dcc_d2a follows reg_en_gyro_drv_dcc_ovrd. reg_gyro_drv_en_dcc_test should also be an output pin of digital_top to DRV IP.
 * Need to be verified and implemented…….
 */
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_EN_DCC_TM_POS      0x06
#define DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_EN_DCC_TM_MASK     (0x01 << DRV_GYR_BAR_29_BYTE_3_GYRO_DRV_EN_DCC_TM_POS)



/*
 * DRV_GYR_BAR_30_BYTE_0
 * Register Name : DRV_GYR_BAR_30_BYTE_0
 */

/*
 * gyro_drv_tm_sniff_reg_sel 
 * Gyro drive system sniff register selector:
 * - 0 fsm state,
 * - 1 some internal signals
 */
#define DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_SNIFF_REG_SEL_POS      0x01
#define DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_SNIFF_REG_SEL_MASK     (0x01 << DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_SNIFF_REG_SEL_POS)

/*
 * gyro_drv_tm_hvd 
 * High voltage driver debug
 * 4: HV drive test system asynchronous reset
 * 3: HV drive test system configuration: +200mV offset on internal test buffer to overcame PAD test buffer low level compatibility
 * 2: HV drive test system configuration: 0 AC divider ping-pong, 1 AC divider differential
 * 1: HV drive test system configuration: 0 AC divider reset 200mV, 1 AC divider reset 400mV
 * 0: HV drive test buffer enable
 */
#define DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_HVD_POS      0x02
#define DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_HVD_MASK     (0x1f << DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_HVD_POS)

/*
 * gyro_drv_tm_hvd_rst_freq 
 * HV drive test system reset pulse frequency: 0 synchronus with refresh, 1 125KHz reset pulse (synchro with drive)
 */
#define DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_HVD_RST_FREQ_POS      0x07
#define DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_HVD_RST_FREQ_MASK     (0x01 << DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_TM_HVD_RST_FREQ_POS)

/*
 * gyro_drv_spare_config_1 
 * Reserved :
 * [0] enables test pass gates
 * [1] set to zero
 * [2] set to zero
 * [3] set to zero
 */
#define DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_SPARE_CONFIG_1_POS      0x00
#define DRV_GYR_BAR_30_BYTE_0_GYRO_DRV_SPARE_CONFIG_1_MASK     0x01



/*
 * DRV_GYR_BAR_30_BYTE_1
 * Register Name : DRV_GYR_BAR_30_BYTE_1
 */

/*
 * gyro_drv_tm_ctrl 
 * FSM debug configuration
 * 3: Enable FSM state force by force register
 * 2: Stop FSM in positive feedback linear drive
 * 1: Stop FSM in normal high frequency
 * 0: Use an external phase shifter clock
 */
#define DRV_GYR_BAR_30_BYTE_1_GYRO_DRV_TM_CTRL_POS      0x04
#define DRV_GYR_BAR_30_BYTE_1_GYRO_DRV_TM_CTRL_MASK     (0x0f << DRV_GYR_BAR_30_BYTE_1_GYRO_DRV_TM_CTRL_POS)

/*
 * gyro_drv_tm_dmd_comp 
 * Demodulator comparator test mode: force input resistor divider active even when dcc loop is off
 */
#define DRV_GYR_BAR_30_BYTE_1_GYRO_DRV_TM_DMD_COMP_POS      0x03
#define DRV_GYR_BAR_30_BYTE_1_GYRO_DRV_TM_DMD_COMP_MASK     (0x01 << DRV_GYR_BAR_30_BYTE_1_GYRO_DRV_TM_DMD_COMP_POS)

/*
 * gyro_drv_spare_config_1 
 * Reserved :
 * [0] enables test pass gates
 * [1] set to zero
 * [2] set to zero
 * [3] set to zero
 */
#define DRV_GYR_BAR_30_BYTE_1_GYRO_DRV_SPARE_CONFIG_1_POS      0x00
#define DRV_GYR_BAR_30_BYTE_1_GYRO_DRV_SPARE_CONFIG_1_MASK     0x07



/*
 * DRV_GYR_BAR_30_BYTE_2
 * Register Name : DRV_GYR_BAR_30_BYTE_2
 */

/*
 * gyro_drv_tm_fsmforce 
 * Drive FSM access to internal state (force)
 */
#define DRV_GYR_BAR_30_BYTE_2_GYRO_DRV_TM_FSMFORCE_POS      0x00
#define DRV_GYR_BAR_30_BYTE_2_GYRO_DRV_TM_FSMFORCE_MASK     0xff



/*
 * DRV_GYR_BAR_30_BYTE_3
 * Register Name : DRV_GYR_BAR_30_BYTE_3
 */

/*
 * gyro_drv_pd_misc_ovrd_b 
 * Power down mask register
 * 7: not connected
 * 6: "hvd_feeback_gm" / High voltage drive feeback gm
 * 5: "phase_shifter" / phase shifter
 * 4: "agc_loop" / AGC loop filter
 * 3: "dmd_comparator" / Demodulato comparator
 * 2: "osc_monitor_comp" / Oscillator monitor comparator
 * 1:"engagment_comp" / loop engage comparator
 * 0: "master_bias" / ip master bias
 */
#define DRV_GYR_BAR_30_BYTE_3_GYRO_DRV_PD_MISC_OVRD_B_POS      0x00
#define DRV_GYR_BAR_30_BYTE_3_GYRO_DRV_PD_MISC_OVRD_B_MASK     0xff



/*
 * PLL_BAR_31_BYTE_0
 * Register Name : PLL_BAR_31_BYTE_0
 */

/*
 * gyro_plldiv 
 * nan
 */
#define PLL_BAR_31_BYTE_0_GYRO_PLLDIV_POS      0x00
#define PLL_BAR_31_BYTE_0_GYRO_PLLDIV_MASK     0x7f



/*
 * PLL_BAR_31_BYTE_1
 * Register Name : PLL_BAR_31_BYTE_1
 */

/*
 * gyro_pllnphi 
 * NOSPUR=1 and phase shift is 70deg
 */
#define PLL_BAR_31_BYTE_1_GYRO_PLLNPHI_POS      0x00
#define PLL_BAR_31_BYTE_1_GYRO_PLLNPHI_MASK     0x7f



/*
 * PLL_BAR_31_BYTE_2
 * Register Name : PLL_BAR_31_BYTE_2
 */

/*
 * gyro_pllicp 
 * nan
 */
#define PLL_BAR_31_BYTE_2_GYRO_PLLICP_POS      0x00
#define PLL_BAR_31_BYTE_2_GYRO_PLLICP_MASK     0x07

/*
 * gyro_pllvco 
 * nan
 */
#define PLL_BAR_31_BYTE_2_GYRO_PLLVCO_POS      0x03
#define PLL_BAR_31_BYTE_2_GYRO_PLLVCO_MASK     (0x0f << PLL_BAR_31_BYTE_2_GYRO_PLLVCO_POS)



/*
 * PLL_BAR_31_BYTE_3
 * Register Name : PLL_BAR_31_BYTE_3
 */

/*
 * gyro_pllvfc 
 * nan
 */
#define PLL_BAR_31_BYTE_3_GYRO_PLLVFC_POS      0x00
#define PLL_BAR_31_BYTE_3_GYRO_PLLVFC_MASK     0x3f

/*
 * gyro_pll_dglitch_count 
 * please update default value
 */
#define PLL_BAR_31_BYTE_3_GYRO_PLL_DGLITCH_COUNT_POS      0x06
#define PLL_BAR_31_BYTE_3_GYRO_PLL_DGLITCH_COUNT_MASK     (0x03 << PLL_BAR_31_BYTE_3_GYRO_PLL_DGLITCH_COUNT_POS)



/*
 * PLL_BAR_32_BYTE_0
 * Register Name : PLL_BAR_32_BYTE_0
 */

/*
 * gyro_pllvcotc 
 * nan
 */
#define PLL_BAR_32_BYTE_0_GYRO_PLLVCOTC_POS      0x00
#define PLL_BAR_32_BYTE_0_GYRO_PLLVCOTC_MASK     0x07

/*
 * osc_vco 
 * nan
 */
#define PLL_BAR_32_BYTE_0_OSC_VCO_POS      0x03
#define PLL_BAR_32_BYTE_0_OSC_VCO_MASK     (0x0f << PLL_BAR_32_BYTE_0_OSC_VCO_POS)



/*
 * PLL_BAR_32_BYTE_1
 * Register Name : PLL_BAR_32_BYTE_1
 */

/*
 * osc_vfc 
 * nan
 */
#define PLL_BAR_32_BYTE_1_OSC_VFC_POS      0x00
#define PLL_BAR_32_BYTE_1_OSC_VFC_MASK     0x3f



/*
 * PLL_BAR_32_BYTE_2
 * Register Name : PLL_BAR_32_BYTE_2
 */

/*
 * osc_vcotc 
 * nan
 */
#define PLL_BAR_32_BYTE_2_OSC_VCOTC_POS      0x00
#define PLL_BAR_32_BYTE_2_OSC_VCOTC_MASK     0x07

/*
 * gyro_pll_osc_spare_otp 
 * nan
 */
#define PLL_BAR_32_BYTE_2_GYRO_PLL_OSC_SPARE_OTP_POS      0x03
#define PLL_BAR_32_BYTE_2_GYRO_PLL_OSC_SPARE_OTP_MASK     (0x1f << PLL_BAR_32_BYTE_2_GYRO_PLL_OSC_SPARE_OTP_POS)



/*
 * PLL_BAR_32_BYTE_3
 * Register Name : PLL_BAR_32_BYTE_3
 */

/*
 * mode 
 * nan
 */
#define PLL_BAR_32_BYTE_3_MODE_POS      0x00
#define PLL_BAR_32_BYTE_3_MODE_MASK     0xff



/*
 * PLL_BAR_33_BYTE_0
 * Register Name : PLL_BAR_33_BYTE_0
 */

/*
 * dis_gyro_pllclk 
 * nan
 */
#define PLL_BAR_33_BYTE_0_DIS_GYRO_PLLCLK_POS      0x00
#define PLL_BAR_33_BYTE_0_DIS_GYRO_PLLCLK_MASK     0x01

/*
 * en_gyro_pll_refbuf 
 * nan
 */
#define PLL_BAR_33_BYTE_0_EN_GYRO_PLL_REFBUF_POS      0x01
#define PLL_BAR_33_BYTE_0_EN_GYRO_PLL_REFBUF_MASK     (0x01 << PLL_BAR_33_BYTE_0_EN_GYRO_PLL_REFBUF_POS)

/*
 * en_gyro_pllreplica 
 * nan
 */
#define PLL_BAR_33_BYTE_0_EN_GYRO_PLLREPLICA_POS      0x02
#define PLL_BAR_33_BYTE_0_EN_GYRO_PLLREPLICA_MASK     (0x01 << PLL_BAR_33_BYTE_0_EN_GYRO_PLLREPLICA_POS)

/*
 * en_gyro_pllrefclk 
 * nan
 */
#define PLL_BAR_33_BYTE_0_EN_GYRO_PLLREFCLK_POS      0x03
#define PLL_BAR_33_BYTE_0_EN_GYRO_PLLREFCLK_MASK     (0x01 << PLL_BAR_33_BYTE_0_EN_GYRO_PLLREFCLK_POS)

/*
 * pllosc_mode 
 * nan
 */
#define PLL_BAR_33_BYTE_0_PLLOSC_MODE_POS      0x05
#define PLL_BAR_33_BYTE_0_PLLOSC_MODE_MASK     (0x01 << PLL_BAR_33_BYTE_0_PLLOSC_MODE_POS)

/*
 * sel_osc_plldiv 
 * nan
 */
#define PLL_BAR_33_BYTE_0_SEL_OSC_PLLDIV_POS      0x06
#define PLL_BAR_33_BYTE_0_SEL_OSC_PLLDIV_MASK     (0x01 << PLL_BAR_33_BYTE_0_SEL_OSC_PLLDIV_POS)

/*
 * en_gyro_pll_dcc 
 * nan
 */
#define PLL_BAR_33_BYTE_0_EN_GYRO_PLL_DCC_POS      0x07
#define PLL_BAR_33_BYTE_0_EN_GYRO_PLL_DCC_MASK     (0x01 << PLL_BAR_33_BYTE_0_EN_GYRO_PLL_DCC_POS)



/*
 * PLL_BAR_33_BYTE_1
 * Register Name : PLL_BAR_33_BYTE_1
 */

/*
 * dis_osc_oscclk 
 * nan
 */
#define PLL_BAR_33_BYTE_1_DIS_OSC_OSCCLK_POS      0x00
#define PLL_BAR_33_BYTE_1_DIS_OSC_OSCCLK_MASK     0x01

/*
 * en_osc_calib 
 * nan
 */
#define PLL_BAR_33_BYTE_1_EN_OSC_CALIB_POS      0x01
#define PLL_BAR_33_BYTE_1_EN_OSC_CALIB_MASK     (0x01 << PLL_BAR_33_BYTE_1_EN_OSC_CALIB_POS)

/*
 * gyro_pll_osc_spare 
 * nan
 */
#define PLL_BAR_33_BYTE_1_GYRO_PLL_OSC_SPARE_POS      0x02
#define PLL_BAR_33_BYTE_1_GYRO_PLL_OSC_SPARE_MASK     (0x3f << PLL_BAR_33_BYTE_1_GYRO_PLL_OSC_SPARE_POS)


/* ---------------------------------------------------------------------------
 * register MMEM_SIGP
 * ---------------------------------------------------------------------------*/

/*
 * ACCEL_X_GOS_0
 * Register Name : ACCEL_X_GOS_0
 */

/*
 * accel_x_gaintc 
 * Accel X gain TC slope. Max allowed gain change is +/- 0.0977 %/K with resolution of 0.00076 %/K
 */
#define ACCEL_X_GOS_0_ACCEL_X_GAINTC_POS      0x00
#define ACCEL_X_GOS_0_ACCEL_X_GAINTC_MASK     0xff



/*
 * ACCEL_X_GOS_1
 * Register Name : ACCEL_X_GOS_1
 */

/*
 * accel_x_cmos_offtc 
 * Accel X CMOS Offset TC slope. Max allowed slope is +/- 3.9 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_X_GOS_1_ACCEL_X_CMOS_OFFTC_POS      0x00
#define ACCEL_X_GOS_1_ACCEL_X_CMOS_OFFTC_MASK     0xff



/*
 * ACCEL_X_GOS_2
 * Register Name : ACCEL_X_GOS_2
 */

/*
 * accel_x_cmos_off_1p5k 
 * Accel X CMOS offset correction for 1.5kHz low-pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_X_GOS_2_ACCEL_X_CMOS_OFF_1P5K_POS      0x00
#define ACCEL_X_GOS_2_ACCEL_X_CMOS_OFF_1P5K_MASK     0xff



/*
 * ACCEL_X_GOS_3
 * Register Name : ACCEL_X_GOS_3
 */

/*
 * accel_x_cmos_off_1p5k 
 * Accel X CMOS offset correction for 1.5kHz low-pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_X_GOS_3_ACCEL_X_CMOS_OFF_1P5K_POS      0x00
#define ACCEL_X_GOS_3_ACCEL_X_CMOS_OFF_1P5K_MASK     0xff



/*
 * ACCEL_X_GOS_4
 * Register Name : ACCEL_X_GOS_4
 */

/*
 * accel_x_cmos_off_0p7k 
 * Accel X CMOS offset correction for 700Hz low-pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_X_GOS_4_ACCEL_X_CMOS_OFF_0P7K_POS      0x00
#define ACCEL_X_GOS_4_ACCEL_X_CMOS_OFF_0P7K_MASK     0xff



/*
 * ACCEL_X_GOS_5
 * Register Name : ACCEL_X_GOS_5
 */

/*
 * accel_x_cmos_off_0p7k 
 * Accel X CMOS offset correction for 700Hz low-pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_X_GOS_5_ACCEL_X_CMOS_OFF_0P7K_POS      0x00
#define ACCEL_X_GOS_5_ACCEL_X_CMOS_OFF_0P7K_MASK     0xff



/*
 * ACCEL_X_GOS_6
 * Register Name : ACCEL_X_GOS_6
 */

/*
 * accel_x_gain 
 * Accel X gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define ACCEL_X_GOS_6_ACCEL_X_GAIN_POS      0x00
#define ACCEL_X_GOS_6_ACCEL_X_GAIN_MASK     0xff



/*
 * ACCEL_X_GOS_7
 * Register Name : ACCEL_X_GOS_7
 */

/*
 * accel_x_gain 
 * Accel X gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define ACCEL_X_GOS_7_ACCEL_X_GAIN_POS      0x00
#define ACCEL_X_GOS_7_ACCEL_X_GAIN_MASK     0x0f

/*
 * accel_x_tmid_gain 
 * Accel X temperature offset wrt room temp for dual slope mems gain-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define ACCEL_X_GOS_7_ACCEL_X_TMID_GAIN_POS      0x04
#define ACCEL_X_GOS_7_ACCEL_X_TMID_GAIN_MASK     (0x07 << ACCEL_X_GOS_7_ACCEL_X_TMID_GAIN_POS)



/*
 * ACCEL_X_GOS_8
 * Register Name : ACCEL_X_GOS_8
 */

/*
 * accel_x_mems_offtc 
 * Accel X MEMS Offset TC slope. Max allowed slope is +/- 15.6 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_X_GOS_8_ACCEL_X_MEMS_OFFTC_POS      0x00
#define ACCEL_X_GOS_8_ACCEL_X_MEMS_OFFTC_MASK     0xff



/*
 * ACCEL_X_GOS_9
 * Register Name : ACCEL_X_GOS_9
 */

/*
 * accel_x_mems_offtc 
 * Accel X MEMS Offset TC slope. Max allowed slope is +/- 15.6 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_X_GOS_9_ACCEL_X_MEMS_OFFTC_POS      0x00
#define ACCEL_X_GOS_9_ACCEL_X_MEMS_OFFTC_MASK     0x03



/*
 * ACCEL_X_GOS_10
 * Register Name : ACCEL_X_GOS_10
 */

/*
 * accel_x_mems_off 
 * Accel X MEMS offset correction. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_X_GOS_10_ACCEL_X_MEMS_OFF_POS      0x00
#define ACCEL_X_GOS_10_ACCEL_X_MEMS_OFF_MASK     0xff



/*
 * ACCEL_X_GOS_11
 * Register Name : ACCEL_X_GOS_11
 */

/*
 * accel_x_mems_off 
 * Accel X MEMS offset correction. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_X_GOS_11_ACCEL_X_MEMS_OFF_POS      0x00
#define ACCEL_X_GOS_11_ACCEL_X_MEMS_OFF_MASK     0xff



/*
 * ACCEL_X_GOS_12
 * Register Name : ACCEL_X_GOS_12
 */

/*
 * accel_x_mems_off_lp 
 * Change in offset on Accel X when accel enters Low Power Mode. Max value is +/-1 gee, resolution is 0.5 mgee
 */
#define ACCEL_X_GOS_12_ACCEL_X_MEMS_OFF_LP_POS      0x00
#define ACCEL_X_GOS_12_ACCEL_X_MEMS_OFF_LP_MASK     0xff



/*
 * ACCEL_X_GOS_13
 * Register Name : ACCEL_X_GOS_13
 */

/*
 * accel_x_mems_off_lp 
 * Change in offset on Accel X when accel enters Low Power Mode. Max value is +/-1 gee, resolution is 0.5 mgee
 */
#define ACCEL_X_GOS_13_ACCEL_X_MEMS_OFF_LP_POS      0x00
#define ACCEL_X_GOS_13_ACCEL_X_MEMS_OFF_LP_MASK     0x0f

/*
 * accel_x_tmid_off 
 * Accel X temperature offset for dual slope mems offset-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define ACCEL_X_GOS_13_ACCEL_X_TMID_OFF_POS      0x04
#define ACCEL_X_GOS_13_ACCEL_X_TMID_OFF_MASK     (0x07 << ACCEL_X_GOS_13_ACCEL_X_TMID_OFF_POS)



/*
 * ACCEL_Y_GOS_0
 * Register Name : ACCEL_Y_GOS_0
 */

/*
 * accel_y_gaintc 
 * Accel Y gain TC slope. Max allowed gain change is +/- 0.0977 %/K with resolution of 0.00076 %/K
 */
#define ACCEL_Y_GOS_0_ACCEL_Y_GAINTC_POS      0x00
#define ACCEL_Y_GOS_0_ACCEL_Y_GAINTC_MASK     0xff



/*
 * ACCEL_Y_GOS_1
 * Register Name : ACCEL_Y_GOS_1
 */

/*
 * accel_y_cmos_offtc 
 * Accel Y CMOS Offset TC slope. Max allowed slope is +/- 3.9 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_Y_GOS_1_ACCEL_Y_CMOS_OFFTC_POS      0x00
#define ACCEL_Y_GOS_1_ACCEL_Y_CMOS_OFFTC_MASK     0xff



/*
 * ACCEL_Y_GOS_2
 * Register Name : ACCEL_Y_GOS_2
 */

/*
 * accel_y_cmos_off_1p5k 
 * Accel Y CMOS offset correction for 1.5kHz low pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Y_GOS_2_ACCEL_Y_CMOS_OFF_1P5K_POS      0x00
#define ACCEL_Y_GOS_2_ACCEL_Y_CMOS_OFF_1P5K_MASK     0xff



/*
 * ACCEL_Y_GOS_3
 * Register Name : ACCEL_Y_GOS_3
 */

/*
 * accel_y_cmos_off_1p5k 
 * Accel Y CMOS offset correction for 1.5kHz low pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Y_GOS_3_ACCEL_Y_CMOS_OFF_1P5K_POS      0x00
#define ACCEL_Y_GOS_3_ACCEL_Y_CMOS_OFF_1P5K_MASK     0xff



/*
 * ACCEL_Y_GOS_4
 * Register Name : ACCEL_Y_GOS_4
 */

/*
 * accel_y_cmos_off_0p7k 
 * Accel Y CMOS offset correction for 700Hz low pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Y_GOS_4_ACCEL_Y_CMOS_OFF_0P7K_POS      0x00
#define ACCEL_Y_GOS_4_ACCEL_Y_CMOS_OFF_0P7K_MASK     0xff



/*
 * ACCEL_Y_GOS_5
 * Register Name : ACCEL_Y_GOS_5
 */

/*
 * accel_y_cmos_off_0p7k 
 * Accel Y CMOS offset correction for 700Hz low pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Y_GOS_5_ACCEL_Y_CMOS_OFF_0P7K_POS      0x00
#define ACCEL_Y_GOS_5_ACCEL_Y_CMOS_OFF_0P7K_MASK     0xff



/*
 * ACCEL_Y_GOS_6
 * Register Name : ACCEL_Y_GOS_6
 */

/*
 * accel_y_gain 
 * Accel Y gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define ACCEL_Y_GOS_6_ACCEL_Y_GAIN_POS      0x00
#define ACCEL_Y_GOS_6_ACCEL_Y_GAIN_MASK     0xff



/*
 * ACCEL_Y_GOS_7
 * Register Name : ACCEL_Y_GOS_7
 */

/*
 * accel_y_gain 
 * Accel Y gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define ACCEL_Y_GOS_7_ACCEL_Y_GAIN_POS      0x00
#define ACCEL_Y_GOS_7_ACCEL_Y_GAIN_MASK     0x0f

/*
 * accel_y_tmid_gain 
 * Accel Y temperature offset wrt room temp for dual slope mems gain-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define ACCEL_Y_GOS_7_ACCEL_Y_TMID_GAIN_POS      0x04
#define ACCEL_Y_GOS_7_ACCEL_Y_TMID_GAIN_MASK     (0x07 << ACCEL_Y_GOS_7_ACCEL_Y_TMID_GAIN_POS)



/*
 * ACCEL_Y_GOS_8
 * Register Name : ACCEL_Y_GOS_8
 */

/*
 * accel_y_mems_offtc 
 * Accel Y MEMS Offset TC slope. Max allowed slope is +/- 15.6 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_Y_GOS_8_ACCEL_Y_MEMS_OFFTC_POS      0x00
#define ACCEL_Y_GOS_8_ACCEL_Y_MEMS_OFFTC_MASK     0xff



/*
 * ACCEL_Y_GOS_9
 * Register Name : ACCEL_Y_GOS_9
 */

/*
 * accel_y_mems_offtc 
 * Accel Y MEMS Offset TC slope. Max allowed slope is +/- 15.6 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_Y_GOS_9_ACCEL_Y_MEMS_OFFTC_POS      0x00
#define ACCEL_Y_GOS_9_ACCEL_Y_MEMS_OFFTC_MASK     0x03



/*
 * ACCEL_Y_GOS_10
 * Register Name : ACCEL_Y_GOS_10
 */

/*
 * accel_y_mems_off 
 * Accel Y MEMS offset correction. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Y_GOS_10_ACCEL_Y_MEMS_OFF_POS      0x00
#define ACCEL_Y_GOS_10_ACCEL_Y_MEMS_OFF_MASK     0xff



/*
 * ACCEL_Y_GOS_11
 * Register Name : ACCEL_Y_GOS_11
 */

/*
 * accel_y_mems_off 
 * Accel Y MEMS offset correction. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Y_GOS_11_ACCEL_Y_MEMS_OFF_POS      0x00
#define ACCEL_Y_GOS_11_ACCEL_Y_MEMS_OFF_MASK     0xff



/*
 * ACCEL_Y_GOS_12
 * Register Name : ACCEL_Y_GOS_12
 */

/*
 * accel_y_mems_off_lp 
 * Change in offset on Accel Y when accel enters Low Power Mode. Max value is +/-1 gee, resolution is 0.5 mgee
 */
#define ACCEL_Y_GOS_12_ACCEL_Y_MEMS_OFF_LP_POS      0x00
#define ACCEL_Y_GOS_12_ACCEL_Y_MEMS_OFF_LP_MASK     0xff



/*
 * ACCEL_Y_GOS_13
 * Register Name : ACCEL_Y_GOS_13
 */

/*
 * accel_y_mems_off_lp 
 * Change in offset on Accel Y when accel enters Low Power Mode. Max value is +/-1 gee, resolution is 0.5 mgee
 */
#define ACCEL_Y_GOS_13_ACCEL_Y_MEMS_OFF_LP_POS      0x00
#define ACCEL_Y_GOS_13_ACCEL_Y_MEMS_OFF_LP_MASK     0x0f

/*
 * accel_y_tmid_off 
 * Accel Y temperature offset for dual slope mems offset-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define ACCEL_Y_GOS_13_ACCEL_Y_TMID_OFF_POS      0x04
#define ACCEL_Y_GOS_13_ACCEL_Y_TMID_OFF_MASK     (0x07 << ACCEL_Y_GOS_13_ACCEL_Y_TMID_OFF_POS)



/*
 * ACCEL_Z_GOS_0
 * Register Name : ACCEL_Z_GOS_0
 */

/*
 * accel_z_gaintc 
 * Accel Z gain TC slope. Max allowed gain change is +/- 0.0977 %/K with resolution of 0.00076 %/K
 */
#define ACCEL_Z_GOS_0_ACCEL_Z_GAINTC_POS      0x00
#define ACCEL_Z_GOS_0_ACCEL_Z_GAINTC_MASK     0xff



/*
 * ACCEL_Z_GOS_1
 * Register Name : ACCEL_Z_GOS_1
 */

/*
 * accel_z_cmos_offtc 
 * Accel Z CMOS Offset TC slope. Max allowed slope is +/- 3.9 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_Z_GOS_1_ACCEL_Z_CMOS_OFFTC_POS      0x00
#define ACCEL_Z_GOS_1_ACCEL_Z_CMOS_OFFTC_MASK     0xff



/*
 * ACCEL_Z_GOS_2
 * Register Name : ACCEL_Z_GOS_2
 */

/*
 * accel_z_cmos_off_1p5k 
 * Accel Z CMOS offset correction for 1.5kHz low pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Z_GOS_2_ACCEL_Z_CMOS_OFF_1P5K_POS      0x00
#define ACCEL_Z_GOS_2_ACCEL_Z_CMOS_OFF_1P5K_MASK     0xff



/*
 * ACCEL_Z_GOS_3
 * Register Name : ACCEL_Z_GOS_3
 */

/*
 * accel_z_cmos_off_1p5k 
 * Accel Z CMOS offset correction for 1.5kHz low pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Z_GOS_3_ACCEL_Z_CMOS_OFF_1P5K_POS      0x00
#define ACCEL_Z_GOS_3_ACCEL_Z_CMOS_OFF_1P5K_MASK     0xff



/*
 * ACCEL_Z_GOS_4
 * Register Name : ACCEL_Z_GOS_4
 */

/*
 * accel_z_cmos_off_0p7k 
 * Accel Z CMOS offset correction for 700Hz low pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Z_GOS_4_ACCEL_Z_CMOS_OFF_0P7K_POS      0x00
#define ACCEL_Z_GOS_4_ACCEL_Z_CMOS_OFF_0P7K_MASK     0xff



/*
 * ACCEL_Z_GOS_5
 * Register Name : ACCEL_Z_GOS_5
 */

/*
 * accel_z_cmos_off_0p7k 
 * Accel Z CMOS offset correction for 700Hz low pass filter configuration. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Z_GOS_5_ACCEL_Z_CMOS_OFF_0P7K_POS      0x00
#define ACCEL_Z_GOS_5_ACCEL_Z_CMOS_OFF_0P7K_MASK     0xff



/*
 * ACCEL_Z_GOS_6
 * Register Name : ACCEL_Z_GOS_6
 */

/*
 * accel_z_gain 
 * Accel Z gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define ACCEL_Z_GOS_6_ACCEL_Z_GAIN_POS      0x00
#define ACCEL_Z_GOS_6_ACCEL_Z_GAIN_MASK     0xff



/*
 * ACCEL_Z_GOS_7
 * Register Name : ACCEL_Z_GOS_7
 */

/*
 * accel_z_gain 
 * Accel Z gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define ACCEL_Z_GOS_7_ACCEL_Z_GAIN_POS      0x00
#define ACCEL_Z_GOS_7_ACCEL_Z_GAIN_MASK     0x0f

/*
 * accel_z_tmid_gain 
 * Accel Z temperature offset wrt room temp for dual slope mems gain-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define ACCEL_Z_GOS_7_ACCEL_Z_TMID_GAIN_POS      0x04
#define ACCEL_Z_GOS_7_ACCEL_Z_TMID_GAIN_MASK     (0x07 << ACCEL_Z_GOS_7_ACCEL_Z_TMID_GAIN_POS)



/*
 * ACCEL_Z_GOS_8
 * Register Name : ACCEL_Z_GOS_8
 */

/*
 * accel_z_mems_offtc 
 * Accel Z MEMS Offset TC slope. Max allowed slope is +/- 15.6 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_Z_GOS_8_ACCEL_Z_MEMS_OFFTC_POS      0x00
#define ACCEL_Z_GOS_8_ACCEL_Z_MEMS_OFFTC_MASK     0xff



/*
 * ACCEL_Z_GOS_9
 * Register Name : ACCEL_Z_GOS_9
 */

/*
 * accel_z_mems_offtc 
 * Accel Z MEMS Offset TC slope. Max allowed slope is +/- 15.6 mgee/K, resolution is 0.0305 mgee/K
 */
#define ACCEL_Z_GOS_9_ACCEL_Z_MEMS_OFFTC_POS      0x00
#define ACCEL_Z_GOS_9_ACCEL_Z_MEMS_OFFTC_MASK     0x03



/*
 * ACCEL_Z_GOS_10
 * Register Name : ACCEL_Z_GOS_10
 */

/*
 * accel_z_mems_off 
 * Accel Z MEMS offset correction. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Z_GOS_10_ACCEL_Z_MEMS_OFF_POS      0x00
#define ACCEL_Z_GOS_10_ACCEL_Z_MEMS_OFF_MASK     0xff



/*
 * ACCEL_Z_GOS_11
 * Register Name : ACCEL_Z_GOS_11
 */

/*
 * accel_z_mems_off 
 * Accel Z MEMS offset correction. Max allowed value is +/-16 gee, with resolution of 0.5 mgee
 */
#define ACCEL_Z_GOS_11_ACCEL_Z_MEMS_OFF_POS      0x00
#define ACCEL_Z_GOS_11_ACCEL_Z_MEMS_OFF_MASK     0xff



/*
 * ACCEL_Z_GOS_12
 * Register Name : ACCEL_Z_GOS_12
 */

/*
 * accel_z_mems_off_lp 
 * Change in offset on Accel Z when accel enters Low Power Mode. Max value is +/-1 gee, resolution is 0.5 mgee
 */
#define ACCEL_Z_GOS_12_ACCEL_Z_MEMS_OFF_LP_POS      0x00
#define ACCEL_Z_GOS_12_ACCEL_Z_MEMS_OFF_LP_MASK     0xff



/*
 * ACCEL_Z_GOS_13
 * Register Name : ACCEL_Z_GOS_13
 */

/*
 * accel_z_mems_off_lp 
 * Change in offset on Accel Z when accel enters Low Power Mode. Max value is +/-1 gee, resolution is 0.5 mgee
 */
#define ACCEL_Z_GOS_13_ACCEL_Z_MEMS_OFF_LP_POS      0x00
#define ACCEL_Z_GOS_13_ACCEL_Z_MEMS_OFF_LP_MASK     0x0f

/*
 * accel_z_tmid_off 
 * Accel Z temperature offset for dual slope mems offset-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define ACCEL_Z_GOS_13_ACCEL_Z_TMID_OFF_POS      0x04
#define ACCEL_Z_GOS_13_ACCEL_Z_TMID_OFF_MASK     (0x07 << ACCEL_Z_GOS_13_ACCEL_Z_TMID_OFF_POS)



/*
 * GYRO_X_GOS_0
 * Register Name : GYRO_X_GOS_0
 */

/*
 * gyro_x_cmos_offtc 
 * Gyro X CMOS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_X_GOS_0_GYRO_X_CMOS_OFFTC_POS      0x00
#define GYRO_X_GOS_0_GYRO_X_CMOS_OFFTC_MASK     0xff



/*
 * GYRO_X_GOS_1
 * Register Name : GYRO_X_GOS_1
 */

/*
 * gyro_x_cmos_offtc 
 * Gyro X CMOS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_X_GOS_1_GYRO_X_CMOS_OFFTC_POS      0x00
#define GYRO_X_GOS_1_GYRO_X_CMOS_OFFTC_MASK     0x3f



/*
 * GYRO_X_GOS_2
 * Register Name : GYRO_X_GOS_2
 */

/*
 * gyro_x_cmos_off 
 * Gyro X CMOS offset correction. Max allowed value is +/-1024 dps, with resolution of 1/32 dps
 */
#define GYRO_X_GOS_2_GYRO_X_CMOS_OFF_POS      0x00
#define GYRO_X_GOS_2_GYRO_X_CMOS_OFF_MASK     0xff



/*
 * GYRO_X_GOS_3
 * Register Name : GYRO_X_GOS_3
 */

/*
 * gyro_x_cmos_off 
 * Gyro X CMOS offset correction. Max allowed value is +/-1024 dps, with resolution of 1/32 dps
 */
#define GYRO_X_GOS_3_GYRO_X_CMOS_OFF_POS      0x00
#define GYRO_X_GOS_3_GYRO_X_CMOS_OFF_MASK     0xff



/*
 * GYRO_X_GOS_4
 * Register Name : GYRO_X_GOS_4
 */

/*
 * gyro_x_gaintcb 
 * Gyro X gain TC slope (setting B)  used above the threshold temperature. Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K
 */
#define GYRO_X_GOS_4_GYRO_X_GAINTCB_POS      0x00
#define GYRO_X_GOS_4_GYRO_X_GAINTCB_MASK     0xff



/*
 * GYRO_X_GOS_5
 * Register Name : GYRO_X_GOS_5
 */

/*
 * gyro_x_gaintca 
 * Gyro X gain TC slope (setting A)  used below the threshold temperature. Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K
 */
#define GYRO_X_GOS_5_GYRO_X_GAINTCA_POS      0x00
#define GYRO_X_GOS_5_GYRO_X_GAINTCA_MASK     0xff



/*
 * GYRO_X_GOS_6
 * Register Name : GYRO_X_GOS_6
 */

/*
 * gyro_x_gain 
 * Gyro X gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define GYRO_X_GOS_6_GYRO_X_GAIN_POS      0x00
#define GYRO_X_GOS_6_GYRO_X_GAIN_MASK     0xff



/*
 * GYRO_X_GOS_7
 * Register Name : GYRO_X_GOS_7
 */

/*
 * gyro_x_gain 
 * Gyro X gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define GYRO_X_GOS_7_GYRO_X_GAIN_POS      0x00
#define GYRO_X_GOS_7_GYRO_X_GAIN_MASK     0x0f

/*
 * gyro_x_tmid_gain 
 * Gyro X temperature offset for dual slope mems gain-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define GYRO_X_GOS_7_GYRO_X_TMID_GAIN_POS      0x04
#define GYRO_X_GOS_7_GYRO_X_TMID_GAIN_MASK     (0x07 << GYRO_X_GOS_7_GYRO_X_TMID_GAIN_POS)



/*
 * GYRO_X_GOS_8
 * Register Name : GYRO_X_GOS_8
 */

/*
 * gyro_x_mems_offtc 
 * Gyro X MEMS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_X_GOS_8_GYRO_X_MEMS_OFFTC_POS      0x00
#define GYRO_X_GOS_8_GYRO_X_MEMS_OFFTC_MASK     0xff



/*
 * GYRO_X_GOS_9
 * Register Name : GYRO_X_GOS_9
 */

/*
 * gyro_x_mems_offtc 
 * Gyro X MEMS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_X_GOS_9_GYRO_X_MEMS_OFFTC_POS      0x00
#define GYRO_X_GOS_9_GYRO_X_MEMS_OFFTC_MASK     0x3f



/*
 * GYRO_X_GOS_10
 * Register Name : GYRO_X_GOS_10
 */

/*
 * gyro_x_mems_off 
 * Gyro X MEMS offset correction. Max allowed value is +/-2048 dps, with resolution of 1/16 dps
 */
#define GYRO_X_GOS_10_GYRO_X_MEMS_OFF_POS      0x00
#define GYRO_X_GOS_10_GYRO_X_MEMS_OFF_MASK     0xff



/*
 * GYRO_X_GOS_11
 * Register Name : GYRO_X_GOS_11
 */

/*
 * gyro_x_mems_off 
 * Gyro X MEMS offset correction. Max allowed value is +/-2048 dps, with resolution of 1/16 dps
 */
#define GYRO_X_GOS_11_GYRO_X_MEMS_OFF_POS      0x00
#define GYRO_X_GOS_11_GYRO_X_MEMS_OFF_MASK     0xff



/*
 * GYRO_X_GOS_12
 * Register Name : GYRO_X_GOS_12
 */

/*
 * gyro_x_mems_off_lp 
 * Change in offset on Gyro X when gyro enters Low Power Mode. Max value is +/-64 dps, resolution is 1/64 dps
 */
#define GYRO_X_GOS_12_GYRO_X_MEMS_OFF_LP_POS      0x00
#define GYRO_X_GOS_12_GYRO_X_MEMS_OFF_LP_MASK     0xff



/*
 * GYRO_X_GOS_13
 * Register Name : GYRO_X_GOS_13
 */

/*
 * gyro_x_mems_off_lp 
 * Change in offset on Gyro X when gyro enters Low Power Mode. Max value is +/-64 dps, resolution is 1/64 dps
 */
#define GYRO_X_GOS_13_GYRO_X_MEMS_OFF_LP_POS      0x00
#define GYRO_X_GOS_13_GYRO_X_MEMS_OFF_LP_MASK     0x0f

/*
 * gyro_x_tmid_off 
 * Gyro X Temperature offset for dual slope mems offset-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define GYRO_X_GOS_13_GYRO_X_TMID_OFF_POS      0x04
#define GYRO_X_GOS_13_GYRO_X_TMID_OFF_MASK     (0x07 << GYRO_X_GOS_13_GYRO_X_TMID_OFF_POS)



/*
 * GYRO_X_GOS_14
 * Register Name : GYRO_X_GOS_14
 */

/*
 * gyro_y2x_mems_cross 
 * Gyro Y-X Cross Axis compensation coefficient
 */
#define GYRO_X_GOS_14_GYRO_Y2X_MEMS_CROSS_POS      0x00
#define GYRO_X_GOS_14_GYRO_Y2X_MEMS_CROSS_MASK     0xff



/*
 * GYRO_X_GOS_15
 * Register Name : GYRO_X_GOS_15
 */

/*
 * gyro_z2x_mems_cross 
 * Gyro Z-X Cross Axis compensation coefficient
 */
#define GYRO_X_GOS_15_GYRO_Z2X_MEMS_CROSS_POS      0x00
#define GYRO_X_GOS_15_GYRO_Z2X_MEMS_CROSS_MASK     0xff



/*
 * GYRO_Y_GOS_0
 * Register Name : GYRO_Y_GOS_0
 */

/*
 * gyro_y_cmos_offtc 
 * Gyro Y CMOS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_Y_GOS_0_GYRO_Y_CMOS_OFFTC_POS      0x00
#define GYRO_Y_GOS_0_GYRO_Y_CMOS_OFFTC_MASK     0xff



/*
 * GYRO_Y_GOS_1
 * Register Name : GYRO_Y_GOS_1
 */

/*
 * gyro_y_cmos_offtc 
 * Gyro Y CMOS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_Y_GOS_1_GYRO_Y_CMOS_OFFTC_POS      0x00
#define GYRO_Y_GOS_1_GYRO_Y_CMOS_OFFTC_MASK     0x3f



/*
 * GYRO_Y_GOS_2
 * Register Name : GYRO_Y_GOS_2
 */

/*
 * gyro_y_cmos_off 
 * Gyro Y CMOS offset correction. Max allowed value is +/-1024 dps, with resolution of 1/32 dps
 */
#define GYRO_Y_GOS_2_GYRO_Y_CMOS_OFF_POS      0x00
#define GYRO_Y_GOS_2_GYRO_Y_CMOS_OFF_MASK     0xff



/*
 * GYRO_Y_GOS_3
 * Register Name : GYRO_Y_GOS_3
 */

/*
 * gyro_y_cmos_off 
 * Gyro Y CMOS offset correction. Max allowed value is +/-1024 dps, with resolution of 1/32 dps
 */
#define GYRO_Y_GOS_3_GYRO_Y_CMOS_OFF_POS      0x00
#define GYRO_Y_GOS_3_GYRO_Y_CMOS_OFF_MASK     0xff



/*
 * GYRO_Y_GOS_4
 * Register Name : GYRO_Y_GOS_4
 */

/*
 * gyro_y_gaintcb 
 * Gyro Y gain TC slope (setting B)  used above the threshold temperature. Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K
 */
#define GYRO_Y_GOS_4_GYRO_Y_GAINTCB_POS      0x00
#define GYRO_Y_GOS_4_GYRO_Y_GAINTCB_MASK     0xff



/*
 * GYRO_Y_GOS_5
 * Register Name : GYRO_Y_GOS_5
 */

/*
 * gyro_y_gaintca 
 * Gyro Y gain TC slope (setting A)  used below the threshold temperature. Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K
 */
#define GYRO_Y_GOS_5_GYRO_Y_GAINTCA_POS      0x00
#define GYRO_Y_GOS_5_GYRO_Y_GAINTCA_MASK     0xff



/*
 * GYRO_Y_GOS_6
 * Register Name : GYRO_Y_GOS_6
 */

/*
 * gyro_y_gain 
 * Gyro Y gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define GYRO_Y_GOS_6_GYRO_Y_GAIN_POS      0x00
#define GYRO_Y_GOS_6_GYRO_Y_GAIN_MASK     0xff



/*
 * GYRO_Y_GOS_7
 * Register Name : GYRO_Y_GOS_7
 */

/*
 * gyro_y_gain 
 * Gyro Y gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define GYRO_Y_GOS_7_GYRO_Y_GAIN_POS      0x00
#define GYRO_Y_GOS_7_GYRO_Y_GAIN_MASK     0x0f

/*
 * gyro_y_tmid_gain 
 * Gyro Y temperature offset for dual slope mems gain-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define GYRO_Y_GOS_7_GYRO_Y_TMID_GAIN_POS      0x04
#define GYRO_Y_GOS_7_GYRO_Y_TMID_GAIN_MASK     (0x07 << GYRO_Y_GOS_7_GYRO_Y_TMID_GAIN_POS)



/*
 * GYRO_Y_GOS_8
 * Register Name : GYRO_Y_GOS_8
 */

/*
 * gyro_y_mems_offtc 
 * Gyro Y MEMS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_Y_GOS_8_GYRO_Y_MEMS_OFFTC_POS      0x00
#define GYRO_Y_GOS_8_GYRO_Y_MEMS_OFFTC_MASK     0xff



/*
 * GYRO_Y_GOS_9
 * Register Name : GYRO_Y_GOS_9
 */

/*
 * gyro_y_mems_offtc 
 * Gyro Y MEMS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_Y_GOS_9_GYRO_Y_MEMS_OFFTC_POS      0x00
#define GYRO_Y_GOS_9_GYRO_Y_MEMS_OFFTC_MASK     0x3f



/*
 * GYRO_Y_GOS_10
 * Register Name : GYRO_Y_GOS_10
 */

/*
 * gyro_y_mems_off 
 * Gyro Y MEMS offset correction. Max allowed value is +/-2048 dps, with resolution of 1/16 dps
 */
#define GYRO_Y_GOS_10_GYRO_Y_MEMS_OFF_POS      0x00
#define GYRO_Y_GOS_10_GYRO_Y_MEMS_OFF_MASK     0xff



/*
 * GYRO_Y_GOS_11
 * Register Name : GYRO_Y_GOS_11
 */

/*
 * gyro_y_mems_off 
 * Gyro Y MEMS offset correction. Max allowed value is +/-2048 dps, with resolution of 1/16 dps
 */
#define GYRO_Y_GOS_11_GYRO_Y_MEMS_OFF_POS      0x00
#define GYRO_Y_GOS_11_GYRO_Y_MEMS_OFF_MASK     0xff



/*
 * GYRO_Y_GOS_12
 * Register Name : GYRO_Y_GOS_12
 */

/*
 * gyro_y_mems_off_lp 
 * Change in offset on Gyro Y when gyro enters Low Power Mode. Max value is +/-64 dps, resolution is 1/64 dps
 */
#define GYRO_Y_GOS_12_GYRO_Y_MEMS_OFF_LP_POS      0x00
#define GYRO_Y_GOS_12_GYRO_Y_MEMS_OFF_LP_MASK     0xff



/*
 * GYRO_Y_GOS_13
 * Register Name : GYRO_Y_GOS_13
 */

/*
 * gyro_y_mems_off_lp 
 * Change in offset on Gyro Y when gyro enters Low Power Mode. Max value is +/-64 dps, resolution is 1/64 dps
 */
#define GYRO_Y_GOS_13_GYRO_Y_MEMS_OFF_LP_POS      0x00
#define GYRO_Y_GOS_13_GYRO_Y_MEMS_OFF_LP_MASK     0x0f

/*
 * gyro_y_tmid_off 
 * Gyro Y Temperature offset for dual slope mems offset-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define GYRO_Y_GOS_13_GYRO_Y_TMID_OFF_POS      0x04
#define GYRO_Y_GOS_13_GYRO_Y_TMID_OFF_MASK     (0x07 << GYRO_Y_GOS_13_GYRO_Y_TMID_OFF_POS)



/*
 * GYRO_Y_GOS_14
 * Register Name : GYRO_Y_GOS_14
 */

/*
 * gyro_z2y_mems_cross 
 * Gyro Z-Y Cross Axis compensation coefficient
 */
#define GYRO_Y_GOS_14_GYRO_Z2Y_MEMS_CROSS_POS      0x00
#define GYRO_Y_GOS_14_GYRO_Z2Y_MEMS_CROSS_MASK     0xff



/*
 * GYRO_Y_GOS_15
 * Register Name : GYRO_Y_GOS_15
 */

/*
 * gyro_x2y_mems_cross 
 * Gyro X-Y Cross Axis compensation coefficient
 */
#define GYRO_Y_GOS_15_GYRO_X2Y_MEMS_CROSS_POS      0x00
#define GYRO_Y_GOS_15_GYRO_X2Y_MEMS_CROSS_MASK     0xff



/*
 * GYRO_Z_GOS_0
 * Register Name : GYRO_Z_GOS_0
 */

/*
 * gyro_z_cmos_offtc 
 * Gyro Z CMOS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_Z_GOS_0_GYRO_Z_CMOS_OFFTC_POS      0x00
#define GYRO_Z_GOS_0_GYRO_Z_CMOS_OFFTC_MASK     0xff



/*
 * GYRO_Z_GOS_1
 * Register Name : GYRO_Z_GOS_1
 */

/*
 * gyro_z_cmos_offtc 
 * Gyro Z CMOS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_Z_GOS_1_GYRO_Z_CMOS_OFFTC_POS      0x00
#define GYRO_Z_GOS_1_GYRO_Z_CMOS_OFFTC_MASK     0x3f



/*
 * GYRO_Z_GOS_2
 * Register Name : GYRO_Z_GOS_2
 */

/*
 * gyro_z_cmos_off 
 * Gyro Z CMOS offset correction. Max allowed value is +/-1024 dps, with resolution of 1/32 dps
 */
#define GYRO_Z_GOS_2_GYRO_Z_CMOS_OFF_POS      0x00
#define GYRO_Z_GOS_2_GYRO_Z_CMOS_OFF_MASK     0xff



/*
 * GYRO_Z_GOS_3
 * Register Name : GYRO_Z_GOS_3
 */

/*
 * gyro_z_cmos_off 
 * Gyro Z CMOS offset correction. Max allowed value is +/-1024 dps, with resolution of 1/32 dps
 */
#define GYRO_Z_GOS_3_GYRO_Z_CMOS_OFF_POS      0x00
#define GYRO_Z_GOS_3_GYRO_Z_CMOS_OFF_MASK     0xff



/*
 * GYRO_Z_GOS_4
 * Register Name : GYRO_Z_GOS_4
 */

/*
 * gyro_z_gaintcb 
 * Gyro Z gain TC slope (setting B)  used above the threshold temperature. Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K
 */
#define GYRO_Z_GOS_4_GYRO_Z_GAINTCB_POS      0x00
#define GYRO_Z_GOS_4_GYRO_Z_GAINTCB_MASK     0xff



/*
 * GYRO_Z_GOS_5
 * Register Name : GYRO_Z_GOS_5
 */

/*
 * gyro_z_gaintca 
 * Gyro Z gain TC slope (setting A)  used below the threshold temperature. Max allowed gain change is +/- 0.0977 %/K, with resolution of 2^-17=0.00076%/K
 */
#define GYRO_Z_GOS_5_GYRO_Z_GAINTCA_POS      0x00
#define GYRO_Z_GOS_5_GYRO_Z_GAINTCA_MASK     0xff



/*
 * GYRO_Z_GOS_6
 * Register Name : GYRO_Z_GOS_6
 */

/*
 * gyro_z_gain 
 * Gyro Z gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define GYRO_Z_GOS_6_GYRO_Z_GAIN_POS      0x00
#define GYRO_Z_GOS_6_GYRO_Z_GAIN_MASK     0xff



/*
 * GYRO_Z_GOS_7
 * Register Name : GYRO_Z_GOS_7
 */

/*
 * gyro_z_gain 
 * Gyro Z gain calibration. Max allowed gain is 2 with resolution of 2^-11=0.05%
 */
#define GYRO_Z_GOS_7_GYRO_Z_GAIN_POS      0x00
#define GYRO_Z_GOS_7_GYRO_Z_GAIN_MASK     0x0f

/*
 * gyro_z_tmid_gain 
 * Gyro Z temperature offset for dual slope mems gain-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define GYRO_Z_GOS_7_GYRO_Z_TMID_GAIN_POS      0x04
#define GYRO_Z_GOS_7_GYRO_Z_TMID_GAIN_MASK     (0x07 << GYRO_Z_GOS_7_GYRO_Z_TMID_GAIN_POS)



/*
 * GYRO_Z_GOS_8
 * Register Name : GYRO_Z_GOS_8
 */

/*
 * gyro_z_mems_offtc 
 * Gyro Z MEMS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_Z_GOS_8_GYRO_Z_MEMS_OFFTC_POS      0x00
#define GYRO_Z_GOS_8_GYRO_Z_MEMS_OFFTC_MASK     0xff



/*
 * GYRO_Z_GOS_9
 * Register Name : GYRO_Z_GOS_9
 */

/*
 * gyro_z_mems_offtc 
 * Gyro Z MEMS Offset TC slope. Max allowed slope is +/- 4dps/Kelvin, resolution is 0.0005 dps/K
 */
#define GYRO_Z_GOS_9_GYRO_Z_MEMS_OFFTC_POS      0x00
#define GYRO_Z_GOS_9_GYRO_Z_MEMS_OFFTC_MASK     0x3f



/*
 * GYRO_Z_GOS_10
 * Register Name : GYRO_Z_GOS_10
 */

/*
 * gyro_z_mems_off 
 * Gyro Z MEMS offset correction. Max allowed value is +/-2048 dps, with resolution of 1/16 dps
 */
#define GYRO_Z_GOS_10_GYRO_Z_MEMS_OFF_POS      0x00
#define GYRO_Z_GOS_10_GYRO_Z_MEMS_OFF_MASK     0xff



/*
 * GYRO_Z_GOS_11
 * Register Name : GYRO_Z_GOS_11
 */

/*
 * gyro_z_mems_off 
 * Gyro Z MEMS offset correction. Max allowed value is +/-2048 dps, with resolution of 1/16 dps
 */
#define GYRO_Z_GOS_11_GYRO_Z_MEMS_OFF_POS      0x00
#define GYRO_Z_GOS_11_GYRO_Z_MEMS_OFF_MASK     0xff



/*
 * GYRO_Z_GOS_12
 * Register Name : GYRO_Z_GOS_12
 */

/*
 * gyro_z_mems_off_lp 
 * Change in offset on Gyro Z when gyro enters Low Power Mode. Max value is +/-64 dps, resolution is 1/64 dps
 */
#define GYRO_Z_GOS_12_GYRO_Z_MEMS_OFF_LP_POS      0x00
#define GYRO_Z_GOS_12_GYRO_Z_MEMS_OFF_LP_MASK     0xff



/*
 * GYRO_Z_GOS_13
 * Register Name : GYRO_Z_GOS_13
 */

/*
 * gyro_z_mems_off_lp 
 * Change in offset on Gyro Z when gyro enters Low Power Mode. Max value is +/-64 dps, resolution is 1/64 dps
 */
#define GYRO_Z_GOS_13_GYRO_Z_MEMS_OFF_LP_POS      0x00
#define GYRO_Z_GOS_13_GYRO_Z_MEMS_OFF_LP_MASK     0x0f

/*
 * gyro_z_tmid_off 
 * Gyro Z Temperature offset for dual slope mems offset-tc in 8 degreeC steps, -28, -20, -12, -4, 4, 12, 20, 28
 */
#define GYRO_Z_GOS_13_GYRO_Z_TMID_OFF_POS      0x04
#define GYRO_Z_GOS_13_GYRO_Z_TMID_OFF_MASK     (0x07 << GYRO_Z_GOS_13_GYRO_Z_TMID_OFF_POS)



/*
 * GYRO_Z_GOS_14
 * Register Name : GYRO_Z_GOS_14
 */

/*
 * gyro_x2z_mems_cross 
 * Gyro X-Z Cross Axis compensation coefficient
 */
#define GYRO_Z_GOS_14_GYRO_X2Z_MEMS_CROSS_POS      0x00
#define GYRO_Z_GOS_14_GYRO_X2Z_MEMS_CROSS_MASK     0xff



/*
 * GYRO_Z_GOS_15
 * Register Name : GYRO_Z_GOS_15
 */

/*
 * gyro_y2z_mems_cross 
 * Gyro Y-Z Cross Axis compensation coefficient
 */
#define GYRO_Z_GOS_15_GYRO_Y2Z_MEMS_CROSS_POS      0x00
#define GYRO_Z_GOS_15_GYRO_Y2Z_MEMS_CROSS_MASK     0xff



/*
 * ACCEL_CONFIG_STATIC0
 * Register Name : ACCEL_CONFIG_STATIC0
 */

/*
 * accel_adc_rec_k 
 * Accel gain corretion parameter for the SD ADC, needed to trimm the alignment among AD and SAR.
 */
#define ACCEL_CONFIG_STATIC0_ACCEL_ADC_REC_K_POS      0x00
#define ACCEL_CONFIG_STATIC0_ACCEL_ADC_REC_K_MASK     0xff



/*
 * ACCEL_CONFIG_STATIC1
 * Register Name : ACCEL_CONFIG_STATIC1
 */

/*
 * accel_adc_rec_k 
 * Accel gain corretion parameter for the SD ADC, needed to trimm the alignment among AD and SAR.
 */
#define ACCEL_CONFIG_STATIC1_ACCEL_ADC_REC_K_POS      0x00
#define ACCEL_CONFIG_STATIC1_ACCEL_ADC_REC_K_MASK     0x1f



/*
 * GYRO_CONFIG_STATIC0
 * Register Name : GYRO_CONFIG_STATIC0
 */

/*
 * gyro_adc_rec_k 
 * Gyro gain corretion parameter for the SD ADC, needed to trimm the alignment among AD and SAR.
 */
#define GYRO_CONFIG_STATIC0_GYRO_ADC_REC_K_POS      0x00
#define GYRO_CONFIG_STATIC0_GYRO_ADC_REC_K_MASK     0xff



/*
 * GYRO_CONFIG_STATIC1
 * Register Name : GYRO_CONFIG_STATIC1
 */

/*
 * gyro_adc_rec_k 
 * Gyro gain corretion parameter for the SD ADC, needed to trimm the alignment among AD and SAR.
 */
#define GYRO_CONFIG_STATIC1_GYRO_ADC_REC_K_POS      0x00
#define GYRO_CONFIG_STATIC1_GYRO_ADC_REC_K_MASK     0x1f



/*
 * GYRO_CONFIG_STATIC2
 * Register Name : GYRO_CONFIG_STATIC2
 */

/*
 * gyro_x_afsr_k 
 * Gyro X AFSR gain error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC2_GYRO_X_AFSR_K_POS      0x00
#define GYRO_CONFIG_STATIC2_GYRO_X_AFSR_K_MASK     0xff



/*
 * GYRO_CONFIG_STATIC3
 * Register Name : GYRO_CONFIG_STATIC3
 */

/*
 * gyro_x_afsr_k 
 * Gyro X AFSR gain error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC3_GYRO_X_AFSR_K_POS      0x00
#define GYRO_CONFIG_STATIC3_GYRO_X_AFSR_K_MASK     0x0f



/*
 * GYRO_CONFIG_STATIC4
 * Register Name : GYRO_CONFIG_STATIC4
 */

/*
 * gyro_y_afsr_k 
 * Gyro Y AFSR gain error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC4_GYRO_Y_AFSR_K_POS      0x00
#define GYRO_CONFIG_STATIC4_GYRO_Y_AFSR_K_MASK     0xff



/*
 * GYRO_CONFIG_STATIC5
 * Register Name : GYRO_CONFIG_STATIC5
 */

/*
 * gyro_y_afsr_k 
 * Gyro Y AFSR gain error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC5_GYRO_Y_AFSR_K_POS      0x00
#define GYRO_CONFIG_STATIC5_GYRO_Y_AFSR_K_MASK     0x0f



/*
 * GYRO_CONFIG_STATIC6
 * Register Name : GYRO_CONFIG_STATIC6
 */

/*
 * gyro_z_afsr_k 
 * Gyro Z AFSR gain error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC6_GYRO_Z_AFSR_K_POS      0x00
#define GYRO_CONFIG_STATIC6_GYRO_Z_AFSR_K_MASK     0xff



/*
 * GYRO_CONFIG_STATIC7
 * Register Name : GYRO_CONFIG_STATIC7
 */

/*
 * gyro_z_afsr_k 
 * Gyro Z AFSR gain error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC7_GYRO_Z_AFSR_K_POS      0x00
#define GYRO_CONFIG_STATIC7_GYRO_Z_AFSR_K_MASK     0x0f



/*
 * GYRO_CONFIG_STATIC8
 * Register Name : GYRO_CONFIG_STATIC8
 */

/*
 * gyro_x_afsr_offset 
 * Gyro X AFSR offset error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC8_GYRO_X_AFSR_OFFSET_POS      0x00
#define GYRO_CONFIG_STATIC8_GYRO_X_AFSR_OFFSET_MASK     0xff



/*
 * GYRO_CONFIG_STATIC9
 * Register Name : GYRO_CONFIG_STATIC9
 */

/*
 * gyro_y_afsr_offset 
 * Gyro Y AFSR offset error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC9_GYRO_Y_AFSR_OFFSET_POS      0x00
#define GYRO_CONFIG_STATIC9_GYRO_Y_AFSR_OFFSET_MASK     0xff



/*
 * GYRO_CONFIG_STATIC10
 * Register Name : GYRO_CONFIG_STATIC10
 */

/*
 * gyro_z_afsr_offset 
 * Gyro Z AFSR offset error compensation.
 * The coefficient is applied to the LFS state.
 */
#define GYRO_CONFIG_STATIC10_GYRO_Z_AFSR_OFFSET_POS      0x00
#define GYRO_CONFIG_STATIC10_GYRO_Z_AFSR_OFFSET_MASK     0xff


/* ---------------------------------------------------------------------------
 * register MREG_TOP1
 * ---------------------------------------------------------------------------*/

/*
 * TMST_CONFIG1
 * Register Name : TMST_CONFIG1
 */

/*
 * odr_en_without_sensors 
 * If high the ODR controller can be enabled even if the sensors are off. 
 * Note:It must be set to 1 to have the ODR controller enabled at any time the RCOSC/PLL is available
 */
#define TMST_CONFIG1_ODR_EN_WITHOUT_SENSORS_POS      0x05
#define TMST_CONFIG1_ODR_EN_WITHOUT_SENSORS_MASK     (0x01 << TMST_CONFIG1_ODR_EN_WITHOUT_SENSORS_POS)

/*
 * tmst_on_sreg_en 
 * TMST operation:
 * 0: Backward compatible mode.
 * 1: Timestamp will be reported in the sense registers when FSYNC is not present.
 */
#define TMST_CONFIG1_TMST_ON_SREG_EN_POS      0x04
#define TMST_CONFIG1_TMST_ON_SREG_EN_MASK     (0x01 << TMST_CONFIG1_TMST_ON_SREG_EN_POS)

/*
 * SENSOR_CONFIG3
 * Register Name : SENSOR_CONFIG3
 */

/*
 * fsync_feature_disable 
 * disable fsync feature
 */
#define SENSOR_CONFIG3_FSYNC_FEATURE_DISABLE_POS      0x05
#define SENSOR_CONFIG3_FSYNC_FEATURE_DISABLE_MASK     (0x01 << SENSOR_CONFIG3_FSYNC_FEATURE_DISABLE_POS)

/*
 * gyro_afsr_feature_disable 
 * disable gyro AFSR: if disabled, the High Full Scale is selected
 */
#define SENSOR_CONFIG3_GYRO_AFSR_FEATURE_DISABLE_POS      0x03
#define SENSOR_CONFIG3_GYRO_AFSR_FEATURE_DISABLE_MASK     (0x01 << SENSOR_CONFIG3_GYRO_AFSR_FEATURE_DISABLE_POS)



/*
 * AFSR_CONFIG0
 * Register Name : AFSR_CONFIG0
 */

/*
 * gyro_afsr_th_high 
 * Values for th_high 
 * [256 384 512(default) 640 768 896 1024]
 */
#define AFSR_CONFIG0_GYRO_AFSR_TH_HIGH_POS      0x03
#define AFSR_CONFIG0_GYRO_AFSR_TH_HIGH_MASK     (0x07 << AFSR_CONFIG0_GYRO_AFSR_TH_HIGH_POS)

/*
 * gyro_afsr_th_low 
 * Values for th_low 
 * [256 384(default) 512 640 768 896 1024]
 */
#define AFSR_CONFIG0_GYRO_AFSR_TH_LOW_POS      0x00
#define AFSR_CONFIG0_GYRO_AFSR_TH_LOW_MASK     0x07



/*
 * AFSR_CONFIG1
 * Register Name : AFSR_CONFIG1
 */

/*
 * gyro_afsr_pls_ext_ind 
 * configuration for the delay used to transition from high full scale to low full scale
 * ind         count     delay[ms]
 * 0          bypass            0
 * 1              16              10
 * 2              32              20    (default)
 * 3              64              40
 * 4             128             80
 * 5             256            160
 * 6             512            320
 * 7            1024           640
 */
#define AFSR_CONFIG1_GYRO_AFSR_PLS_EXT_IND_POS      0x00
#define AFSR_CONFIG1_GYRO_AFSR_PLS_EXT_IND_MASK     0x07



/*
 * SPARE0_TRIM
 * Register Name : SPARE0_TRIM
 */

/*
 * spare0_trim 
 * Space reserved for Test team / Product team for productization
 */
#define SPARE0_TRIM_SPARE0_TRIM_POS      0x00
#define SPARE0_TRIM_SPARE0_TRIM_MASK     0xff



/*
 * SPARE1_TRIM
 * Register Name : SPARE1_TRIM
 */

/*
 * spare1_trim 
 * Space reserved for Test team / Product team for productization
 */
#define SPARE1_TRIM_SPARE1_TRIM_POS      0x00
#define SPARE1_TRIM_SPARE1_TRIM_MASK     0xff



/*
 * SPARE2_TRIM
 * Register Name : SPARE2_TRIM
 */

/*
 * spare2_trim 
 * Space reserved for Test team / Product team for productization
 */
#define SPARE2_TRIM_SPARE2_TRIM_POS      0x00
#define SPARE2_TRIM_SPARE2_TRIM_MASK     0xff



/*
 * SPARE3_TRIM
 * Register Name : SPARE3_TRIM
 */

/*
 * spare3_trim 
 * Space reserved for Test team / Product team for productization
 */
#define SPARE3_TRIM_SPARE3_TRIM_POS      0x00
#define SPARE3_TRIM_SPARE3_TRIM_MASK     0xff



/*
 * TBC_RCOSC
 * Register Name : TBC_RCOSC
 */

/*
 * tbc_rcosc_trim 
 * Not used
 */
#define TBC_RCOSC_TBC_RCOSC_TRIM_POS      0x00
#define TBC_RCOSC_TBC_RCOSC_TRIM_MASK     0xff



/*
 * TBC_PLL
 * Register Name : TBC_PLL
 */

/*
 * tbc_pll_trim 
 * Not used
 */
#define TBC_PLL_TBC_PLL_TRIM_POS      0x00
#define TBC_PLL_TBC_PLL_TRIM_MASK     0xff



/*
 * ZA_SENSITIIVY
 * Register Name : ZA_SENSITIIVY
 */

/*
 * za_sens_acc_trim 
 * Z axis sensistivity stored by OPS team - used for recalibration
 */
#define ZA_SENSITIIVY_ZA_SENS_ACC_TRIM_POS      0x00
#define ZA_SENSITIIVY_ZA_SENS_ACC_TRIM_MASK     0xff



/*
 * GXSENSERELP
 * Register Name : GXSENSERELP
 */

/*
 * gxsenserelp 
 * nan
 */
#define GXSENSERELP_GXSENSERELP_POS      0x00
#define GXSENSERELP_GXSENSERELP_MASK     0xff



/*
 * GYSENSERELP
 * Register Name : GYSENSERELP
 */

/*
 * gysenserelp 
 * nan
 */
#define GYSENSERELP_GYSENSERELP_POS      0x00
#define GYSENSERELP_GYSENSERELP_MASK     0xff



/*
 * GZSENSERELP
 * Register Name : GZSENSERELP
 */

/*
 * gzsenserelp 
 * nan
 */
#define GZSENSERELP_GZSENSERELP_POS      0x00
#define GZSENSERELP_GZSENSERELP_MASK     0xff



/*
 * INTF_CONFIG4
 * Register Name : INTF_CONFIG4
 */

/*
 * sreg_lsb_dither_en 
 * 0 means SREG LSB dithering  is disabled (A1 mode)
 * 1 means SREG LSB  dithering  is enabled
 */
#define INTF_CONFIG4_SREG_LSB_DITHER_EN_POS      0x02
#define INTF_CONFIG4_SREG_LSB_DITHER_EN_MASK     (0x01 << INTF_CONFIG4_SREG_LSB_DITHER_EN_POS)



/*
 * PADS_CONFIG1
 * Register Name : PADS_CONFIG1
 */

/*
 * pads_tp_areg_trim_d2a 
 * If necessary, depending on the regulator used, these bits may be used to trim the avdd voltage in IO pads
 */
#define PADS_CONFIG1_PADS_TP_AREG_TRIM_D2A_POS      0x00
#define PADS_CONFIG1_PADS_TP_AREG_TRIM_D2A_MASK     0x1f



/*
 * PADS_CONFIG3
 * Register Name : PADS_CONFIG3
 */

/*
 * pads_avdd_mon_d2a 
 * Pin function: when high, connects io_reg_avdd inside pads_top to one of the atp bus. 
 * Requirement at system level: when high, should not allow any other IP to connect to atp bus.
 */
#define PADS_CONFIG3_PADS_AVDD_MON_D2A_POS      0x07
#define PADS_CONFIG3_PADS_AVDD_MON_D2A_MASK     (0x01 << PADS_CONFIG3_PADS_AVDD_MON_D2A_POS)

/*
 * pads_tp_lpbk_d2a 
 * Pin function: when high, shorts two of the atp bus.
 * Requirement at system level: when high, should not allow any other IP to connect to atp bus.
 */
#define PADS_CONFIG3_PADS_TP_LPBK_D2A_POS      0x06
#define PADS_CONFIG3_PADS_TP_LPBK_D2A_MASK     (0x01 << PADS_CONFIG3_PADS_TP_LPBK_D2A_POS)

/*
 * pads_chop_freq_sel 
 * Controls the chop operation of analog buffers in the padring. (Shared across all 4 test pins)
 * 0- 0 --:  parked at 0 , no chopping
 * 1 - 1--:  parked at 1 , no chopping
 * 1x : 1 MHz --:  1 MHz chopping
 */
#define PADS_CONFIG3_PADS_CHOP_FREQ_SEL_POS      0x04
#define PADS_CONFIG3_PADS_CHOP_FREQ_SEL_MASK     (0x03 << PADS_CONFIG3_PADS_CHOP_FREQ_SEL_POS)

/*
 * en_pads_tp_avdd_d2a 
 * Enables the Analog Regulator in the PADRing. This bit needs to be set if we desire to use the analog test bus mode. This  bit  enables the clock required for the analog regulator  . Clock signal clk_pads_4m_d2a and associated enable  signal en_clk_pads_4m_d2d from big digital
 */
#define PADS_CONFIG3_EN_PADS_TP_AVDD_D2A_POS      0x03
#define PADS_CONFIG3_EN_PADS_TP_AVDD_D2A_MASK     (0x01 << PADS_CONFIG3_EN_PADS_TP_AVDD_D2A_POS)



/*
 * PADS_CONFIG4
 * Register Name : PADS_CONFIG4
 */

/*
 * pads_int1_tp0_dtpbus_en_d2a 
 * Enable as digital test point
 */
#define PADS_CONFIG4_PADS_INT1_TP0_DTPBUS_EN_D2A_POS      0x07
#define PADS_CONFIG4_PADS_INT1_TP0_DTPBUS_EN_D2A_MASK     (0x01 << PADS_CONFIG4_PADS_INT1_TP0_DTPBUS_EN_D2A_POS)

/*
 * pads_int1_tp0_atpbus_en_d2a 
 * Enable as analog test
 */
#define PADS_CONFIG4_PADS_INT1_TP0_ATPBUS_EN_D2A_POS      0x06
#define PADS_CONFIG4_PADS_INT1_TP0_ATPBUS_EN_D2A_MASK     (0x01 << PADS_CONFIG4_PADS_INT1_TP0_ATPBUS_EN_D2A_POS)

/*
 * pads_int1_tp0_abuf_en_d2a 
 * Enable as Analog Buffer condition
 */
#define PADS_CONFIG4_PADS_INT1_TP0_ABUF_EN_D2A_POS      0x05
#define PADS_CONFIG4_PADS_INT1_TP0_ABUF_EN_D2A_MASK     (0x01 << PADS_CONFIG4_PADS_INT1_TP0_ABUF_EN_D2A_POS)

/*
 * pads_int1_tp0_anl_sel_d2a 
 * Enable as Analog condition
 */
#define PADS_CONFIG4_PADS_INT1_TP0_ANL_SEL_D2A_POS      0x04
#define PADS_CONFIG4_PADS_INT1_TP0_ANL_SEL_D2A_MASK     (0x01 << PADS_CONFIG4_PADS_INT1_TP0_ANL_SEL_D2A_POS)

/*
 * pads_int1_tp0_od 
 * Open Drain
 */
#define PADS_CONFIG4_PADS_INT1_TP0_OD_POS      0x03
#define PADS_CONFIG4_PADS_INT1_TP0_OD_MASK     (0x01 << PADS_CONFIG4_PADS_INT1_TP0_OD_POS)

/*
 * pads_int1_tp0_tp_oe 
 * Output enable
 */
#define PADS_CONFIG4_PADS_INT1_TP0_TP_OE_POS      0x02
#define PADS_CONFIG4_PADS_INT1_TP0_TP_OE_MASK     (0x01 << PADS_CONFIG4_PADS_INT1_TP0_TP_OE_POS)

/*
 * pads_int1_tp0_tp_en_d2a 
 * Pad enable
 */
#define PADS_CONFIG4_PADS_INT1_TP0_TP_EN_D2A_POS      0x01
#define PADS_CONFIG4_PADS_INT1_TP0_TP_EN_D2A_MASK     (0x01 << PADS_CONFIG4_PADS_INT1_TP0_TP_EN_D2A_POS)

/*
 * pads_int1_tp0_from_pad_disable_d2a 
 * Disable from pad function
 */
#define PADS_CONFIG4_PADS_INT1_TP0_FROM_PAD_DISABLE_D2A_POS      0x00
#define PADS_CONFIG4_PADS_INT1_TP0_FROM_PAD_DISABLE_D2A_MASK     0x01



/*
 * PADS_CONFIG5
 * Register Name : PADS_CONFIG5
 */

/*
 * pads_fsync_tp1_dtpbus_en_d2a 
 * Enable as digital test point
 */
#define PADS_CONFIG5_PADS_FSYNC_TP1_DTPBUS_EN_D2A_POS      0x07
#define PADS_CONFIG5_PADS_FSYNC_TP1_DTPBUS_EN_D2A_MASK     (0x01 << PADS_CONFIG5_PADS_FSYNC_TP1_DTPBUS_EN_D2A_POS)

/*
 * pads_fsync_tp1_atpbus_en_d2a 
 * Enable as analog test
 */
#define PADS_CONFIG5_PADS_FSYNC_TP1_ATPBUS_EN_D2A_POS      0x06
#define PADS_CONFIG5_PADS_FSYNC_TP1_ATPBUS_EN_D2A_MASK     (0x01 << PADS_CONFIG5_PADS_FSYNC_TP1_ATPBUS_EN_D2A_POS)

/*
 * pads_fsync_tp1_abuf_en_d2a 
 * Enable as Analog Buffer condition
 */
#define PADS_CONFIG5_PADS_FSYNC_TP1_ABUF_EN_D2A_POS      0x05
#define PADS_CONFIG5_PADS_FSYNC_TP1_ABUF_EN_D2A_MASK     (0x01 << PADS_CONFIG5_PADS_FSYNC_TP1_ABUF_EN_D2A_POS)

/*
 * pads_fsync_tp1_anl_sel_d2a 
 * Enable as Analog condition
 */
#define PADS_CONFIG5_PADS_FSYNC_TP1_ANL_SEL_D2A_POS      0x04
#define PADS_CONFIG5_PADS_FSYNC_TP1_ANL_SEL_D2A_MASK     (0x01 << PADS_CONFIG5_PADS_FSYNC_TP1_ANL_SEL_D2A_POS)

/*
 * pads_fsync_tp1_od_d2a 
 * Open Drain
 */
#define PADS_CONFIG5_PADS_FSYNC_TP1_OD_D2A_POS      0x03
#define PADS_CONFIG5_PADS_FSYNC_TP1_OD_D2A_MASK     (0x01 << PADS_CONFIG5_PADS_FSYNC_TP1_OD_D2A_POS)

/*
 * pads_fsync_tp1_tp_oe 
 * Output enable
 */
#define PADS_CONFIG5_PADS_FSYNC_TP1_TP_OE_POS      0x02
#define PADS_CONFIG5_PADS_FSYNC_TP1_TP_OE_MASK     (0x01 << PADS_CONFIG5_PADS_FSYNC_TP1_TP_OE_POS)

/*
 * pads_fsync_tp1_tp_en_d2a 
 * Pad enable
 */
#define PADS_CONFIG5_PADS_FSYNC_TP1_TP_EN_D2A_POS      0x01
#define PADS_CONFIG5_PADS_FSYNC_TP1_TP_EN_D2A_MASK     (0x01 << PADS_CONFIG5_PADS_FSYNC_TP1_TP_EN_D2A_POS)

/*
 * pads_fsync_tp1_from_pad_disable_d2a 
 * Disable from pad function
 */
#define PADS_CONFIG5_PADS_FSYNC_TP1_FROM_PAD_DISABLE_D2A_POS      0x00
#define PADS_CONFIG5_PADS_FSYNC_TP1_FROM_PAD_DISABLE_D2A_MASK     0x01



/*
 * PADS_CONFIG6
 * Register Name : PADS_CONFIG6
 */

/*
 * pads_int2_tp2_dtpbus_en_d2a 
 * Enable as digital test point
 */
#define PADS_CONFIG6_PADS_INT2_TP2_DTPBUS_EN_D2A_POS      0x07
#define PADS_CONFIG6_PADS_INT2_TP2_DTPBUS_EN_D2A_MASK     (0x01 << PADS_CONFIG6_PADS_INT2_TP2_DTPBUS_EN_D2A_POS)

/*
 * pads_int2_tp2_atpbus_en_d2a 
 * Enable as analog test
 */
#define PADS_CONFIG6_PADS_INT2_TP2_ATPBUS_EN_D2A_POS      0x06
#define PADS_CONFIG6_PADS_INT2_TP2_ATPBUS_EN_D2A_MASK     (0x01 << PADS_CONFIG6_PADS_INT2_TP2_ATPBUS_EN_D2A_POS)

/*
 * pads_int2_tp2_abuf_en_d2a 
 * Enable as Analog Buffer condition
 */
#define PADS_CONFIG6_PADS_INT2_TP2_ABUF_EN_D2A_POS      0x05
#define PADS_CONFIG6_PADS_INT2_TP2_ABUF_EN_D2A_MASK     (0x01 << PADS_CONFIG6_PADS_INT2_TP2_ABUF_EN_D2A_POS)

/*
 * pads_int2_tp2_anl_sel_d2a 
 * Enable as Analog condition
 */
#define PADS_CONFIG6_PADS_INT2_TP2_ANL_SEL_D2A_POS      0x04
#define PADS_CONFIG6_PADS_INT2_TP2_ANL_SEL_D2A_MASK     (0x01 << PADS_CONFIG6_PADS_INT2_TP2_ANL_SEL_D2A_POS)

/*
 * pads_int2_tp2_od 
 * Open Drain
 */
#define PADS_CONFIG6_PADS_INT2_TP2_OD_POS      0x03
#define PADS_CONFIG6_PADS_INT2_TP2_OD_MASK     (0x01 << PADS_CONFIG6_PADS_INT2_TP2_OD_POS)

/*
 * pads_int2_tp2_tp_oe 
 * Output enable
 */
#define PADS_CONFIG6_PADS_INT2_TP2_TP_OE_POS      0x02
#define PADS_CONFIG6_PADS_INT2_TP2_TP_OE_MASK     (0x01 << PADS_CONFIG6_PADS_INT2_TP2_TP_OE_POS)

/*
 * pads_int2_tp2_tp_en_d2a 
 * Pad enable
 */
#define PADS_CONFIG6_PADS_INT2_TP2_TP_EN_D2A_POS      0x01
#define PADS_CONFIG6_PADS_INT2_TP2_TP_EN_D2A_MASK     (0x01 << PADS_CONFIG6_PADS_INT2_TP2_TP_EN_D2A_POS)

/*
 * pads_int2_tp2_from_pad_disable_d2a 
 * Disable from pad function
 */
#define PADS_CONFIG6_PADS_INT2_TP2_FROM_PAD_DISABLE_D2A_POS      0x00
#define PADS_CONFIG6_PADS_INT2_TP2_FROM_PAD_DISABLE_D2A_MASK     0x01



/*
 * PADS_CONFIG7
 * Register Name : PADS_CONFIG7
 */

/*
 * pads_tp3_dtpbus_en_d2a 
 * Enable as digital test point
 */
#define PADS_CONFIG7_PADS_TP3_DTPBUS_EN_D2A_POS      0x07
#define PADS_CONFIG7_PADS_TP3_DTPBUS_EN_D2A_MASK     (0x01 << PADS_CONFIG7_PADS_TP3_DTPBUS_EN_D2A_POS)

/*
 * pads_tp3_atpbus_en_d2a 
 * Enable as analog test
 */
#define PADS_CONFIG7_PADS_TP3_ATPBUS_EN_D2A_POS      0x06
#define PADS_CONFIG7_PADS_TP3_ATPBUS_EN_D2A_MASK     (0x01 << PADS_CONFIG7_PADS_TP3_ATPBUS_EN_D2A_POS)

/*
 * pads_tp3_abuf_en_d2a 
 * Enable as Analog Buffer condition
 */
#define PADS_CONFIG7_PADS_TP3_ABUF_EN_D2A_POS      0x05
#define PADS_CONFIG7_PADS_TP3_ABUF_EN_D2A_MASK     (0x01 << PADS_CONFIG7_PADS_TP3_ABUF_EN_D2A_POS)

/*
 * pads_tp3_anl_sel_d2a 
 * Enable as Analog condition
 */
#define PADS_CONFIG7_PADS_TP3_ANL_SEL_D2A_POS      0x04
#define PADS_CONFIG7_PADS_TP3_ANL_SEL_D2A_MASK     (0x01 << PADS_CONFIG7_PADS_TP3_ANL_SEL_D2A_POS)

/*
 * pads_tp3_od_d2a 
 * Open Drain
 */
#define PADS_CONFIG7_PADS_TP3_OD_D2A_POS      0x03
#define PADS_CONFIG7_PADS_TP3_OD_D2A_MASK     (0x01 << PADS_CONFIG7_PADS_TP3_OD_D2A_POS)

/*
 * pads_tp3_tp_oe 
 * Output enable
 */
#define PADS_CONFIG7_PADS_TP3_TP_OE_POS      0x02
#define PADS_CONFIG7_PADS_TP3_TP_OE_MASK     (0x01 << PADS_CONFIG7_PADS_TP3_TP_OE_POS)

/*
 * pads_tp3_tp_en_d2a 
 * Pad enable
 */
#define PADS_CONFIG7_PADS_TP3_TP_EN_D2A_POS      0x01
#define PADS_CONFIG7_PADS_TP3_TP_EN_D2A_MASK     (0x01 << PADS_CONFIG7_PADS_TP3_TP_EN_D2A_POS)

/*
 * pads_tp3_from_pad_disable_d2a 
 * Disable from pad function
 */
#define PADS_CONFIG7_PADS_TP3_FROM_PAD_DISABLE_D2A_POS      0x00
#define PADS_CONFIG7_PADS_TP3_FROM_PAD_DISABLE_D2A_MASK     0x01



/*
 * TEMP_CONFIG1
 * Register Name : TEMP_CONFIG1
 */

/*
 * temp_offset 
 *  Register offset to set the register zero to 25degC
 */
#define TEMP_CONFIG1_TEMP_OFFSET_POS      0x00
#define TEMP_CONFIG1_TEMP_OFFSET_MASK     0x7f



/*
 * TEMP_CONFIG2
 * Register Name : TEMP_CONFIG2
 */

/*
 * temp_cotrim 
 *  Trimming codeword to compensate for parasitic capacitance in the temp sensor ADC integrative capacitance that prevent to match analog with digital β regenerative gain
 */
#define TEMP_CONFIG2_TEMP_COTRIM_POS      0x00
#define TEMP_CONFIG2_TEMP_COTRIM_MASK     0x7f



/*
 * TEMP_CONFIG3
 * Register Name : TEMP_CONFIG3
 */

/*
 * temp_dem 
 * Enable Dynamic Element Selection (DEM) mode
 */
#define TEMP_CONFIG3_TEMP_DEM_POS      0x02
#define TEMP_CONFIG3_TEMP_DEM_MASK     (0x01 << TEMP_CONFIG3_TEMP_DEM_POS)

/*
 * temp_comp_dis 
 * New variant of the temperature sensor disable "feature", which also sets the temperature compensation as if the chip were at room temperature. The "old" temp_dis remains with the same feature as in Yokohama, and it still uses the last registered value for temperature code.
 */
#define TEMP_CONFIG3_TEMP_COMP_DIS_POS      0x01
#define TEMP_CONFIG3_TEMP_COMP_DIS_MASK     (0x01 << TEMP_CONFIG3_TEMP_COMP_DIS_POS)



/*
 * INTF_CONFIG6
 * Register Name : INTF_CONFIG6
 */

/*
 * i3c_bcr_bit0 
 * Description.
 *   0: means slave does not have max data speed limitation.
 *   1: means slave has max data speed limitation. User need to issue GETMXDS
 * command for detail max data speed limitation information
 */
#define INTF_CONFIG6_I3C_BCR_BIT0_POS      0x06
#define INTF_CONFIG6_I3C_BCR_BIT0_MASK     (0x01 << INTF_CONFIG6_I3C_BCR_BIT0_POS)

/*
 * i3c_s0s1_timeout_en 
 * Value of 1 to enable i3c's s0s1 error timeout function
 */
#define INTF_CONFIG6_I3C_S0S1_TIMEOUT_EN_POS      0x05
#define INTF_CONFIG6_I3C_S0S1_TIMEOUT_EN_MASK     (0x01 << INTF_CONFIG6_I3C_S0S1_TIMEOUT_EN_POS)

/*
 * INTF_CONFIG11
 * Register Name : INTF_CONFIG11
 */

/*
 * rcosc_force_on_trim 
 * 1: force rcosc 4MHz clock free running
 */
#define INTF_CONFIG11_RCOSC_FORCE_ON_TRIM_POS      0x07
#define INTF_CONFIG11_RCOSC_FORCE_ON_TRIM_MASK     (0x01 << INTF_CONFIG11_RCOSC_FORCE_ON_TRIM_POS)

/*
 * wuosc_6p4k_force_on 
 * 1: force wuosc 6.4KHz clock free running
 */
#define INTF_CONFIG11_WUOSC_6P4K_FORCE_ON_POS      0x06
#define INTF_CONFIG11_WUOSC_6P4K_FORCE_ON_MASK     (0x01 << INTF_CONFIG11_WUOSC_6P4K_FORCE_ON_POS)

/*
 * i3c_getmxds_maxrd 
 * [2:0]: max sustained data rate for non-CCC message from salve to host.
 *       [5:3]: Clock to data turn around time (Tsco).
 *              0: <= 8ns.
 *              1: <= 9ns.
 *              2: <= 10ns.
 *              3: <= 11ns.
 *              4: <= 12ns.
 *              5: reserved.    
 *              6: reserved.
 *              7: :  12ns (see private agreement).
 */
#define INTF_CONFIG11_I3C_GETMXDS_MAXRD_POS      0x00
#define INTF_CONFIG11_I3C_GETMXDS_MAXRD_MASK     0x3f



/*
 * INTF_CONFIG10
 * Register Name : INTF_CONFIG10
 */

/*
 * i3c_getmxds_maxwr 
 * Maximum Sustained Data Rate for non-CCC messages sent by Slave Device to Master Device : 
 * 0: fSCL Max (default value)
 * 1: 8 MHz
 * 2: 6 MHz
 * 3: 4 MHz
 * 4: 2 MHz
 * 5–7: Reserved for future use by the MIPI Alliance
 * 
 * User can configure with Register[ ADDR: ‘d36] bit [2:0]
 */
#define INTF_CONFIG10_I3C_GETMXDS_MAXWR_POS      0x00
#define INTF_CONFIG10_I3C_GETMXDS_MAXWR_MASK     0x07



/*
 * INTF_COMM_ERR
 * Register Name : INTF_COMM_ERR
 */

/*
 * i3c_s0_err 
 * Detect any of the following: 
 *                                7’h3E / W
 *                                7’h5E / W
 *                                7’h6E / W
 *                                7’h76 / W 
 *                                7’h7A / W
 *                                7’h7C / W
 *                                7’h7F / W
 *                                7’h7E / R
 * As per specification assert when above describe Address Header receive by I3C
 */
#define INTF_COMM_ERR_I3C_S0_ERR_POS      0x05
#define INTF_COMM_ERR_I3C_S0_ERR_MASK     (0x01 << INTF_COMM_ERR_I3C_S0_ERR_POS)

/*
 * i3c_ccc_parity_err 
 * If the I3C detects a parity error during a CCC code, 
 * then the Slave will not be able to know that the I3C Bus has changed to HDR Mode if the CCC is ENTHDR.
 * 
 * In order  to  avoid  this  situation,  if   the  I3C  detects  a  parity  error  during  a  CCC  code,  then  the  I3C  shall ignore the rest of the signal, until the HDR EXIT pattern is detected
 */
#define INTF_COMM_ERR_I3C_CCC_PARITY_ERR_POS      0x04
#define INTF_COMM_ERR_I3C_CCC_PARITY_ERR_MASK     (0x01 << INTF_COMM_ERR_I3C_CCC_PARITY_ERR_POS)

/*
 * i3c_sdr_parity_err 
 * Error will occur when I3C operating in SDR mode and parity check fail with any I3C message
 */
#define INTF_COMM_ERR_I3C_SDR_PARITY_ERR_POS      0x03
#define INTF_COMM_ERR_I3C_SDR_PARITY_ERR_MASK     (0x01 << INTF_COMM_ERR_I3C_SDR_PARITY_ERR_POS)

/*
 * i3c_ddr_parity_err 
 * Error occur when I3C operating in HDR-DDR mode check bad parity for both CMD and DATA
 */
#define INTF_COMM_ERR_I3C_DDR_PARITY_ERR_POS      0x02
#define INTF_COMM_ERR_I3C_DDR_PARITY_ERR_MASK     (0x01 << INTF_COMM_ERR_I3C_DDR_PARITY_ERR_POS)

/*
 * i3c_ddr_framing_err 
 * Error occur when I3C operating in HDR-DDR mode bad preamble. We check CMD (01) and CMD-: READ which is 1Z
 */
#define INTF_COMM_ERR_I3C_DDR_FRAMING_ERR_POS      0x01
#define INTF_COMM_ERR_I3C_DDR_FRAMING_ERR_MASK     (0x01 << INTF_COMM_ERR_I3C_DDR_FRAMING_ERR_POS)

/*
 * i3c_crc_err 
 * Error occur when I3C operating in HDR-DDR mode :
 * CRC encoding (for transmitters) and CRC checking (for receivers) shall be performed on all payload bits for Command Words and Data Words.
 * Mismatched CRC is an Error.
 */
#define INTF_COMM_ERR_I3C_CRC_ERR_POS      0x00
#define INTF_COMM_ERR_I3C_CRC_ERR_MASK     0x01



/*
 * INTF_CONFIG5
 * Register Name : INTF_CONFIG5
 */

/*
 * i3c_sda_dly 
 * Description:
 *  [1:0] is used to add delay for SDA signal from SDA pad to SIFS slave. This delay is applicable only when I3C slave IP is used for both I3C or I2C operation. This delay is not applicable when in SPI mode, or using legacy 
 *        I2C slave.
 *        0: no dly.
 *        1: sda input delay = 1*6.4ns.
 *        2: sda input delay = 2*6.4ns.
 *        3: sda input delay = 4*6.4ns.
 * 
 *  [3:2] is used to add delay for SDA signal from I3C slave to SIFS slave. This delay is applicable only when I3C slave IP is used for  both I3C or I2C operation. This delay is not applicable when in SPI mode, or using legacy 
 *        I2C slave.
 *        0: no dly.
 *        1:  sda output delay = 1*6.4ns.
 *        2:  sda output delay = 2*6.4ns.
 *        3:  sda output delay = 4*6.4ns.
 */
#define INTF_CONFIG5_I3C_SDA_DLY_POS      0x04
#define INTF_CONFIG5_I3C_SDA_DLY_MASK     (0x0f << INTF_CONFIG5_I3C_SDA_DLY_POS)

/*
 * ibi_force_sda_timeout_trim 
 * Determines the behavior of the Self-Driven START.
 * 0: IBI generates a Self-Driven START condition at every Bus Available condition, as described in the v1.0 I3C spec.
 * 1: A Self-Driven START condition times out after 1ms without the I3C Master pulling the SCL line low, and doesn’t occur again until after the next START condition, as proposed for the v1.1 I3C spec.
 */
#define INTF_CONFIG5_IBI_FORCE_SDA_TIMEOUT_TRIM_POS      0x03
#define INTF_CONFIG5_IBI_FORCE_SDA_TIMEOUT_TRIM_MASK     (0x01 << INTF_CONFIG5_IBI_FORCE_SDA_TIMEOUT_TRIM_POS)



/*
 * INTF_CONFIG7
 * Register Name : INTF_CONFIG7
 */

/*
 * i3c_ignore_s0 
 * This bit controls how I3C slave treats the 1st 2-byte data from 
 *     host in a DDR write operation. 
 * 
 *     0: (a) The 1st-byte in DDR-WR configures the starting register
 *            address where the write operation should occur. 
 *        (b) The 2nd-byte in DDR-WR is ignored and dropped. 
 *        (c) The 3rd-byte in DDR-WR will be written into the register 
 *            with address specified by the 1st-byte.
 *            Or, the next DDR-RD will be starting from the address 
 *            specified by the 1st-byte of previous DDR-WR.
 * 
 *     1:  (a) The 1st-byte in DDR-WR configures the starting register 
 *             address where the write operation should occur. 
 *         (b) The 2nd-byte in DDR-WR will be written into the register 
 *             with address specified by the 1st-byte.
 */
#define INTF_CONFIG7_I3C_IGNORE_S0_POS      0x02
#define INTF_CONFIG7_I3C_IGNORE_S0_MASK     (0x01 << INTF_CONFIG7_I3C_IGNORE_S0_POS)

/*
 * i3c_dcr 
 * I3C Device character register.
 * 2'b00: DCR is 8'h44 for 6-axis sensor.
 * 2'b01: DCR is 8'h41 for 3-axis accel.
 * 2'b10: DCR is 8'h42 for 3-axis gyro.
 * 2'b11: DCR is 8'h46 for 9-axis Gyro/Accel/Mag.
 */
#define INTF_CONFIG7_I3C_DCR_POS      0x00
#define INTF_CONFIG7_I3C_DCR_MASK     0x03



/*
 * INTF_CONFIG8
 * Register Name : INTF_CONFIG8
 */

/*
 * i3c_part 
 * I3C unique part number.
 */
#define INTF_CONFIG8_I3C_PART_POS      0x00
#define INTF_CONFIG8_I3C_PART_MASK     0xff



/*
 * INTF_CONFIG9
 * Register Name : INTF_CONFIG9
 */

/*
 * i3c_timeout_event 
 * Value of 1 means i2c/i3c timeout event has occurred
 */
#define INTF_CONFIG9_I3C_TIMEOUT_EVENT_POS      0x07
#define INTF_CONFIG9_I3C_TIMEOUT_EVENT_MASK     (0x01 << INTF_CONFIG9_I3C_TIMEOUT_EVENT_POS)

/*
 * i3c_activity_mode 
 * Contains the two-bit ID of the Slave Device's current Activity Mode (readiness to suort data read of sensor or related information)
 */
#define INTF_CONFIG9_I3C_ACTIVITY_MODE_POS      0x05
#define INTF_CONFIG9_I3C_ACTIVITY_MODE_MASK     (0x03 << INTF_CONFIG9_I3C_ACTIVITY_MODE_POS)

/*
 * i3c_protocol_err 
 * If set to 1'b1 then the Slave detected a protocol error since the last Status read. Self clearing register after read  by master
 */
#define INTF_CONFIG9_I3C_PROTOCOL_ERR_POS      0x04
#define INTF_CONFIG9_I3C_PROTOCOL_ERR_MASK     (0x01 << INTF_CONFIG9_I3C_PROTOCOL_ERR_POS)

/*
 * i3c_pending_interrupt 
 * Contains the  interrupt number of any  pending interrupt or 0 if no  interrupts are pending. This encoding allows for 15 interrupts. If more than one interrupt is set, then the highest  priority interrupt shall be returned
 */
#define INTF_CONFIG9_I3C_PENDING_INTERRUPT_POS      0x00
#define INTF_CONFIG9_I3C_PENDING_INTERRUPT_MASK     0x0f



/*
 * OTP_CONFIG
 * Register Name : OTP_CONFIG
 */

/*
 * otp_valid_bank 
 * OTP load status
 * 0: Tthe DMA hasn’t found any valid OTP bank and didn’t perform OTP loading
 * 1,2,3 -:  Index of the valid bank found by DMA
 */
#define OTP_CONFIG_OTP_VALID_BANK_POS      0x00
#define OTP_CONFIG_OTP_VALID_BANK_MASK     0x03



/*
 * DMP_CONFIG1
 * Register Name : DMP_CONFIG1
 */

/*
 * dmp_apex_start_addr 
 * APEX program starting address:
 * 0 - 31 : 32*dmp_progr_start_address (range 0x0000 - 0x03E0)
 * 32 - 127: 0x0400 + 32*dmp_progr_start_address (range (0x0800 - 0x13E0)
 * default 0x0BA0 (code 61)
 */
#define DMP_CONFIG1_DMP_APEX_START_ADDR_POS      0x00
#define DMP_CONFIG1_DMP_APEX_START_ADDR_MASK     0x7f



/*
 * DMP_CONFIG2
 * Register Name : DMP_CONFIG2
 */

/*
 * dmp_st_start_addr 
 * Self-test program starting address.
 */
#define DMP_CONFIG2_DMP_ST_START_ADDR_POS      0x00
#define DMP_CONFIG2_DMP_ST_START_ADDR_MASK     0xff



/*
 * DMP_RESERVED
 * Register Name : DMP_RESERVED
 */

/*
 * dmp_reserved 
 * Reserved for DMP
 */
#define DMP_RESERVED_DMP_RESERVED_POS      0x00
#define DMP_RESERVED_DMP_RESERVED_MASK     0xff



/*
 * MISC_3
 * Register Name : MISC_3
 */

/*
 * otp_rld_ibi_gate_dis 
 * Controls IBI transfer to SIFS  during OTP reload.
 * 0: IBI to SIFS is gated off during OTP reload.
 * 1: IBI to SIFS is not gated off during OTP reload.
 */
#define MISC_3_OTP_RLD_IBI_GATE_DIS_POS      0x06
#define MISC_3_OTP_RLD_IBI_GATE_DIS_MASK     (0x01 << MISC_3_OTP_RLD_IBI_GATE_DIS_POS)

/*
 * low_pri_mstr 
 * Specify SOI master priority.
 * [0] : 1, master 0 (SIFS) to be moved to low priority bucket.
 * [1] : 1, master 1 (DMP) to be moved to low prioirty bucket.
 * [2] : 1, master 2 (FIDO) to be moved to low priority bucket.
 */
#define MISC_3_LOW_PRI_MSTR_POS      0x03
#define MISC_3_LOW_PRI_MSTR_MASK     (0x07 << MISC_3_LOW_PRI_MSTR_POS)

/*
 * ram_margin 
 * SRAM timing Marging Control
 * 00: highest margin, slowest SRAM speed
 * 10: default
 * 11: least margin, fastest SRAM speed
 */
#define MISC_3_RAM_MARGIN_POS      0x01
#define MISC_3_RAM_MARGIN_MASK     (0x03 << MISC_3_RAM_MARGIN_POS)

/*
 * ram_pd 
 * SRAM power Down  control
 * 1: SRAm powered down
 * 0: SRAM power up
 */
#define MISC_3_RAM_PD_POS      0x00
#define MISC_3_RAM_PD_MASK     0x01



/*
 * MISC_4
 * Register Name : MISC_4
 */

/*
 * hot_join_mode 
 * 0: Only participate ENTDAA operation after slave has made hot_join request to host.
 * 1: Slave participates ENTDAA operation whenever it is available.
 */
#define MISC_4_HOT_JOIN_MODE_POS      0x01
#define MISC_4_HOT_JOIN_MODE_MASK     (0x01 << MISC_4_HOT_JOIN_MODE_POS)

/*
 * hot_join_en 
 * 1: To enable hot join feature.
 * 0: To disable hot join feature.
 */
#define MISC_4_HOT_JOIN_EN_POS      0x00
#define MISC_4_HOT_JOIN_EN_MASK     0x01



/*
 * TEST_REG0
 * Register Name : TEST_REG0
 */

/*
 * sigpath_test_shift 
 * select which shift is applied to sigpath_test_reg for appling it at the input of the signal path
 * 
 * 2'd0: SD_ADC= {sigpath_test_reg[5:0] ,2’d0}
 *         SAR_ADC = 11’d0
 * 
 * 2'd2: SD_ADC= {(5) sigpath_test_reg[5],sigpath_test_reg[5:3]}
 *         SAR_ADC = {sigpath_test_reg[2:0] ,9’d0}
 * 
 * 2'd2: SD_ADC= {(8) sigpath_test_reg[5]}
 *         SAR_ADC = {sigpath_test_reg[5],sigpath_test_reg[5:0] ,5’d0}
 * 
 * 2'd3: SD_ADC= {(8) sigpath_test_reg[5]}
 *         SAR_ADC = {(6) sigpath_test_reg[5],sigpath_test_reg[5:0] }
 */
#define TEST_REG0_SIGPATH_TEST_SHIFT_POS      0x06
#define TEST_REG0_SIGPATH_TEST_SHIFT_MASK     (0x03 << TEST_REG0_SIGPATH_TEST_SHIFT_POS)

/*
 * sigpath_short_test_reg 
 * signal to be forced at the input of the signal path when sigpath_test_en=1
 */
#define TEST_REG0_SIGPATH_SHORT_TEST_REG_POS      0x00
#define TEST_REG0_SIGPATH_SHORT_TEST_REG_MASK     0x3f



/*
 * TEST_REG2
 * Register Name : TEST_REG2
 */

/*
 * arc_init 
 * Set to 1 and write into one BAR to get all BAR's reset
 */
#define TEST_REG2_ARC_INIT_POS      0x03
#define TEST_REG2_ARC_INIT_MASK     (0x01 << TEST_REG2_ARC_INIT_POS)

/*
 * gyro_4m_force_on 
 * 1: to force gyro 4MHz clock running.
 */
#define TEST_REG2_GYRO_4M_FORCE_ON_POS      0x02
#define TEST_REG2_GYRO_4M_FORCE_ON_MASK     (0x01 << TEST_REG2_GYRO_4M_FORCE_ON_POS)

/*
 * accel_4m_force_on 
 * 1: to force accel 4MHz clock running
 */
#define TEST_REG2_ACCEL_4M_FORCE_ON_POS      0x01
#define TEST_REG2_ACCEL_4M_FORCE_ON_MASK     (0x01 << TEST_REG2_ACCEL_4M_FORCE_ON_POS)



/*
 * GYRO_PWR_CFG0
 * Register Name : GYRO_PWR_CFG0
 */

/*
 * gyro_drv_safe_state_force 
 * forces  gyro_drv_state to 1 as interpreted by power sequencer
 */
#define GYRO_PWR_CFG0_GYRO_DRV_SAFE_STATE_FORCE_POS      0x05
#define GYRO_PWR_CFG0_GYRO_DRV_SAFE_STATE_FORCE_MASK     (0x01 << GYRO_PWR_CFG0_GYRO_DRV_SAFE_STATE_FORCE_POS)

/*
 * gyro_drv_agc_on_force 
 * forces agc_on to 1 as interpreted by power sequencer
 */
#define GYRO_PWR_CFG0_GYRO_DRV_AGC_ON_FORCE_POS      0x04
#define GYRO_PWR_CFG0_GYRO_DRV_AGC_ON_FORCE_MASK     (0x01 << GYRO_PWR_CFG0_GYRO_DRV_AGC_ON_FORCE_POS)

/*
 * pll_rdy_force 
 * forces agc_on to 1 as interpreted by power sequencer
 */
#define GYRO_PWR_CFG0_PLL_RDY_FORCE_POS      0x03
#define GYRO_PWR_CFG0_PLL_RDY_FORCE_MASK     (0x01 << GYRO_PWR_CFG0_PLL_RDY_FORCE_POS)

/*
 * gyro_pll_ref_clk_rdy_force 
 * gdrive_PLL_ref_ck_rdy_ovrd in Athens/Paris
 */
#define GYRO_PWR_CFG0_GYRO_PLL_REF_CLK_RDY_FORCE_POS      0x01
#define GYRO_PWR_CFG0_GYRO_PLL_REF_CLK_RDY_FORCE_MASK     (0x01 << GYRO_PWR_CFG0_GYRO_PLL_REF_CLK_RDY_FORCE_POS)

/*
 * gyro_cp25v_cprdy_force 
 * Force bit for ana_gyro_cp25v_cprdy
 */
#define GYRO_PWR_CFG0_GYRO_CP25V_CPRDY_FORCE_POS      0x00
#define GYRO_PWR_CFG0_GYRO_CP25V_CPRDY_FORCE_MASK     0x01



/*
 * ACCEL_CP_CFG0
 * Register Name : ACCEL_CP_CFG0
 */

/*
 * pd_accel_cp_b 
 * nan
 */
#define ACCEL_CP_CFG0_PD_ACCEL_CP_B_POS      0x03
#define ACCEL_CP_CFG0_PD_ACCEL_CP_B_MASK     (0x01 << ACCEL_CP_CFG0_PD_ACCEL_CP_B_POS)

/*
 * rst_accel_force 
 * nan
 */
#define ACCEL_CP_CFG0_RST_ACCEL_FORCE_POS      0x01
#define ACCEL_CP_CFG0_RST_ACCEL_FORCE_MASK     (0x01 << ACCEL_CP_CFG0_RST_ACCEL_FORCE_POS)



/*
 * CP_25V_CFG0
 * Register Name : CP_25V_CFG0
 */

/*
 * pd_gyro_cp25v_b 
 * Power-down Override (to 0V). 
 * 0: pd_gyro_cp25v_b_d2a dynamic signal (output of digital top) should be forced to 0, 
 * 1: pd_gyro_cp25v_b_d2a should follow the specified dynamic behavior.
 */
#define CP_25V_CFG0_PD_GYRO_CP25V_B_POS      0x06
#define CP_25V_CFG0_PD_GYRO_CP25V_B_MASK     (0x01 << CP_25V_CFG0_PD_GYRO_CP25V_B_POS)



/*
 * PLL_LP_CFG1
 * Register Name : PLL_LP_CFG1
 */

/*
 * en_gyro_pll_dcc_force 
 * Duty-cycle correction enable overide. 
 * 1: forces en_gyro_pll_dcc_d2a =1 and en_gyro_drv_dcc_d2a=1, 
 * 0: en_gyro_pll_dcc_d2a = (en_gyro_drv_dcc_ovrd && <appropriate power sequencer state, based on timing diagram: ), and en_gyro_drv_dcc_d2a = en_gyro_pll_dcc_d2a || gyro_drv_en_dcc_test;
 */
#define PLL_LP_CFG1_EN_GYRO_PLL_DCC_FORCE_POS      0x05
#define PLL_LP_CFG1_EN_GYRO_PLL_DCC_FORCE_MASK     (0x01 << PLL_LP_CFG1_EN_GYRO_PLL_DCC_FORCE_POS)

/*
 * en_gyro_pll_calib 
 * PLL calibration enable overide. 
 * 0: en_gyro_pllcalib_d2a should follow dynamic behavior from power-sequencer; 
 * 1: forces en_gyro_pllcalib_d2a=1.
 */
#define PLL_LP_CFG1_EN_GYRO_PLL_CALIB_POS      0x04
#define PLL_LP_CFG1_EN_GYRO_PLL_CALIB_MASK     (0x01 << PLL_LP_CFG1_EN_GYRO_PLL_CALIB_POS)



/*
 * AMP_GSXYZ_CFG0
 * Register Name : AMP_GSXYZ_CFG0
 */

/*
 * pd_gyro_sc2v_b 
 * Gyro Xasix SC2V power bar override 0: force pd_gx_sc2v_b to 0
 */
#define AMP_GSXYZ_CFG0_PD_GYRO_SC2V_B_POS      0x03
#define AMP_GSXYZ_CFG0_PD_GYRO_SC2V_B_MASK     (0x01 << AMP_GSXYZ_CFG0_PD_GYRO_SC2V_B_POS)



/*
 * DMD_GCT_CFG0
 * Register Name : DMD_GCT_CFG0
 */

/*
 * rst_gyro_adc_b 
 * Gyro demod ADC reset_b override (common to 3 axes). 
 * 0: rst_gyro_adc_b_d2a dynamic signal (output of digital top) should be forced to 0, 
 * 1: rst_gyro_adc_b_d2a should follow the specified dynamic behavior.
 */
#define DMD_GCT_CFG0_RST_GYRO_ADC_B_POS      0x07
#define DMD_GCT_CFG0_RST_GYRO_ADC_B_MASK     (0x01 << DMD_GCT_CFG0_RST_GYRO_ADC_B_POS)

/*
 * pd_gyro_dmd_b 
 * Gyro demod main pd_b override. 
 * 0: pd_g<axis: _dmd_b_d2a dynamic signal (output of digital top) should be forced to 0, 
 * 1: pd_g<axis: _dmd_b_d2a should follow the specified dynamic behavior.
 */
#define DMD_GCT_CFG0_PD_GYRO_DMD_B_POS      0x00
#define DMD_GCT_CFG0_PD_GYRO_DMD_B_MASK     0x01



/*
 * TMP_ISD_CFG0
 * Register Name : TMP_ISD_CFG0
 */

/*
 * pd_tmp_bias_b_ovrd 
 * Allows the Temp Sensor Bias to be always powered up
 */
#define TMP_ISD_CFG0_PD_TMP_BIAS_B_OVRD_POS      0x07
#define TMP_ISD_CFG0_PD_TMP_BIAS_B_OVRD_MASK     (0x01 << TMP_ISD_CFG0_PD_TMP_BIAS_B_OVRD_POS)

/*
 * pd_tmp_b_ovrd 
 * Allows the Temp Sennsor to be  always powered up
 */
#define TMP_ISD_CFG0_PD_TMP_B_OVRD_POS      0x06
#define TMP_ISD_CFG0_PD_TMP_B_OVRD_MASK     (0x01 << TMP_ISD_CFG0_PD_TMP_B_OVRD_POS)

/*
 * en_clk_tmp_4m_ovrd 
 * When high this overrides temperature 4MHz clock to be always ON
 */
#define TMP_ISD_CFG0_EN_CLK_TMP_4M_OVRD_POS      0x05
#define TMP_ISD_CFG0_EN_CLK_TMP_4M_OVRD_MASK     (0x01 << TMP_ISD_CFG0_EN_CLK_TMP_4M_OVRD_POS)

/*
 * pd_tmp_b 
 * temperature sensor power-on (Is this coming from Power manager ? Is this an over ride bit ? - Is the over-ride on analog side or digital side?)
 */
#define TMP_ISD_CFG0_PD_TMP_B_POS      0x00
#define TMP_ISD_CFG0_PD_TMP_B_MASK     0x01



/*
 * DIG_CLK_CFG0
 * Register Name : DIG_CLK_CFG0
 */

/*
 * gyro_dmd_sync_b 
 * When set to 0, overrides the GDM sync signal to 0.  This is used by the production test team when calibrating the phase.
 */
#define DIG_CLK_CFG0_GYRO_DMD_SYNC_B_POS      0x05
#define DIG_CLK_CFG0_GYRO_DMD_SYNC_B_MASK     (0x01 << DIG_CLK_CFG0_GYRO_DMD_SYNC_B_POS)

/*
 * rst_gyro_dmd_b 
 * When set to 0, overrides the GDM reset signal to 0, which also clock-gates the gyro demod outputs of the GDM block, but leaves the rst_gyro_dc2v_sw_b signal toggling as configured.  This is used by the production test team when calibrating the phase, and also to measure the power of the gyro demod digital circuit in silicon.  Setting this register to 0 also asserts the reset (rst_gyro_dmd_b_a2a) for the local div-2 flops in the gyro demod analog.
 */
#define DIG_CLK_CFG0_RST_GYRO_DMD_B_POS      0x04
#define DIG_CLK_CFG0_RST_GYRO_DMD_B_MASK     (0x01 << DIG_CLK_CFG0_RST_GYRO_DMD_B_POS)



/*
 * PSEQ_STATUS
 * Register Name : PSEQ_STATUS
 */

/*
 * pseq_accel_wuosc_mode 
 * Debug bits for PSEQ
 */
#define PSEQ_STATUS_PSEQ_ACCEL_WUOSC_MODE_POS      0x07
#define PSEQ_STATUS_PSEQ_ACCEL_WUOSC_MODE_MASK     (0x01 << PSEQ_STATUS_PSEQ_ACCEL_WUOSC_MODE_POS)

/*
 * pseq_trig_accel_lp_shared_off 
 * Debug bits for PSEQ
 */
#define PSEQ_STATUS_PSEQ_TRIG_ACCEL_LP_SHARED_OFF_POS      0x06
#define PSEQ_STATUS_PSEQ_TRIG_ACCEL_LP_SHARED_OFF_MASK     (0x01 << PSEQ_STATUS_PSEQ_TRIG_ACCEL_LP_SHARED_OFF_POS)

/*
 * pseq_gyro_off 
 * Debug bits for PSEQ
 */
#define PSEQ_STATUS_PSEQ_GYRO_OFF_POS      0x04
#define PSEQ_STATUS_PSEQ_GYRO_OFF_MASK     (0x01 << PSEQ_STATUS_PSEQ_GYRO_OFF_POS)

/*
 * pseq_gyro_stdby 
 * Debug bits for PSEQ
 */
#define PSEQ_STATUS_PSEQ_GYRO_STDBY_POS      0x03
#define PSEQ_STATUS_PSEQ_GYRO_STDBY_MASK     (0x01 << PSEQ_STATUS_PSEQ_GYRO_STDBY_POS)

/*
 * pseq_gyro_on 
 * Debug bits for PSEQ
 */
#define PSEQ_STATUS_PSEQ_GYRO_ON_POS      0x02
#define PSEQ_STATUS_PSEQ_GYRO_ON_MASK     (0x01 << PSEQ_STATUS_PSEQ_GYRO_ON_POS)

/*
 * pseq_accel_off 
 * Debug bits for PSEQ
 */
#define PSEQ_STATUS_PSEQ_ACCEL_OFF_POS      0x01
#define PSEQ_STATUS_PSEQ_ACCEL_OFF_MASK     (0x01 << PSEQ_STATUS_PSEQ_ACCEL_OFF_POS)

/*
 * pseq_accel_on 
 * Debug bits for PSEQ
 */
#define PSEQ_STATUS_PSEQ_ACCEL_ON_POS      0x00
#define PSEQ_STATUS_PSEQ_ACCEL_ON_MASK     0x01



/*
 * MB_CORE_STATUS0
 * Register Name : MB_CORE_STATUS0
 */

/*
 * mbcore_rctrim_cnt_a2d 
 * MB_CORE RC-trim counter output for crtmom measurement
 */
#define MB_CORE_STATUS0_MBCORE_RCTRIM_CNT_A2D_POS      0x00
#define MB_CORE_STATUS0_MBCORE_RCTRIM_CNT_A2D_MASK     0xff



/*
 * MB_CORE_STATUS1
 * Register Name : MB_CORE_STATUS1
 */

/*
 * mbcore_rctrim_cnt_a2d 
 * MB_CORE RC-trim counter output for crtmom measurement
 */
#define MB_CORE_STATUS1_MBCORE_RCTRIM_CNT_A2D_POS      0x00
#define MB_CORE_STATUS1_MBCORE_RCTRIM_CNT_A2D_MASK     0x01



/*
 * DRV_GYR_STATUS0
 * Register Name : DRV_GYR_STATUS0
 */

/*
 * gyro_drv_test_fsmread_a2d 
 * gyro_drv_spare2_d2a<1:  = 0
 *  fsm_state<7:0: 
 * gyro_drv_spare2_d2a<1:  = 1
 * [7]: low 
 * [6]: dig_gn_n 
 * [5]: dig_gn_p 
 * [4]: dig_gp_n 
 * [3]: dig_gp_p 
 * [2]: dig_pll_ref_rdy 
 * [1]: dig_agc_on 
 * [0]: drv_gyr_lock
 */
#define DRV_GYR_STATUS0_GYRO_DRV_TEST_FSMREAD_A2D_POS      0x00
#define DRV_GYR_STATUS0_GYRO_DRV_TEST_FSMREAD_A2D_MASK     0xff



/*
 * SIGP_CFG0
 * Register Name : SIGP_CFG0
 */

/*
 * gyro_interp_fin_sel 
 * Gyro interpolator Fin = 1/Tin trimmed  as ROUND(2^15/(1.5*gyro_plldiv)) - 256.gyro_plldivis the PLL divider.
 * Also  ROUND(2^15*FDrive/(3*Fclk_1m)) - 256  (being Fclk_1m = 1.0368MHz)
 */
#define SIGP_CFG0_GYRO_INTERP_FIN_SEL_POS      0x00
#define SIGP_CFG0_GYRO_INTERP_FIN_SEL_MASK     0xff



/*
 * SIGP_CFG1
 * Register Name : SIGP_CFG1
 */

/*
 * odr_dec_bypass_invalid 
 * When high : In Low noise, If ODR decimation is bypassed and the sensor data is invalid.
 */
#define SIGP_CFG1_ODR_DEC_BYPASS_INVALID_POS      0x06
#define SIGP_CFG1_ODR_DEC_BYPASS_INVALID_MASK     (0x01 << SIGP_CFG1_ODR_DEC_BYPASS_INVALID_POS)

/*
 * sigp_mem_default 
 * When high : The memory set to default value.
 */
#define SIGP_CFG1_SIGP_MEM_DEFAULT_POS      0x05
#define SIGP_CFG1_SIGP_MEM_DEFAULT_MASK     (0x01 << SIGP_CFG1_SIGP_MEM_DEFAULT_POS)

/*
 * sigp_mem_clk_sel 
 * When high: SOI bus has access to Sensor Path Shared Memory. When low: the Sensor Hardware has access to the Memory.
 */
#define SIGP_CFG1_SIGP_MEM_CLK_SEL_POS      0x04
#define SIGP_CFG1_SIGP_MEM_CLK_SEL_MASK     (0x01 << SIGP_CFG1_SIGP_MEM_CLK_SEL_POS)

/*
 * gyro_afsr_shared_mode 
 * If set, all gyro channels will be set to HFS if at least one of them sets to HFS.
 */
#define SIGP_CFG1_GYRO_AFSR_SHARED_MODE_POS      0x03
#define SIGP_CFG1_GYRO_AFSR_SHARED_MODE_MASK     (0x01 << SIGP_CFG1_GYRO_AFSR_SHARED_MODE_POS)

/*
 * gyro_afsr_en 
 * this enables AFSR: it is only used if afsr_disable_feature is off (otherwise HFS)
 * To enable AFSR:
 * gyro_afsr_disable_feature = FALSE
 * gyro_afsr_en = TRUE
 * then the gyro_afsr_mode controls the effective setting
 */
#define SIGP_CFG1_GYRO_AFSR_EN_POS      0x00
#define SIGP_CFG1_GYRO_AFSR_EN_MASK     0x01



/*
 * SIGP_CFG2
 * Register Name : SIGP_CFG2
 */

/*
 * gyro_chop_pl_z 
 * It’s compared to the input  adc control port: ana_adc_chop. When different sar adc data  & sd adc data are twos complemented.  
 */
#define SIGP_CFG2_GYRO_CHOP_PL_Z_POS      0x05
#define SIGP_CFG2_GYRO_CHOP_PL_Z_MASK     (0x01 << SIGP_CFG2_GYRO_CHOP_PL_Z_POS)

/*
 * gyro_chop_pl_y 
 * It’s compared to the input  adc control port: ana_adc_chop. When different sar adc data  & sd adc data are twos complemented.  
 */
#define SIGP_CFG2_GYRO_CHOP_PL_Y_POS      0x04
#define SIGP_CFG2_GYRO_CHOP_PL_Y_MASK     (0x01 << SIGP_CFG2_GYRO_CHOP_PL_Y_POS)

/*
 * gyro_chop_pl_x 
 * It’s compared to the input  adc control port: ana_adc_chop. When different sar adc data  & sd adc data are twos complemented.  
 */
#define SIGP_CFG2_GYRO_CHOP_PL_X_POS      0x03
#define SIGP_CFG2_GYRO_CHOP_PL_X_MASK     (0x01 << SIGP_CFG2_GYRO_CHOP_PL_X_POS)

/*
 * accel_chop_pl_z 
 * It’s compared to the input  adc control port: ana_adc_chop. When different sar adc data  & sd adc data are twos complemented.  
 */
#define SIGP_CFG2_ACCEL_CHOP_PL_Z_POS      0x02
#define SIGP_CFG2_ACCEL_CHOP_PL_Z_MASK     (0x01 << SIGP_CFG2_ACCEL_CHOP_PL_Z_POS)

/*
 * accel_chop_pl_y 
 * It’s compared to the input  adc control port: ana_adc_chop. When different sar adc data  & sd adc data are twos complemented.  
 */
#define SIGP_CFG2_ACCEL_CHOP_PL_Y_POS      0x01
#define SIGP_CFG2_ACCEL_CHOP_PL_Y_MASK     (0x01 << SIGP_CFG2_ACCEL_CHOP_PL_Y_POS)

/*
 * accel_chop_pl_x 
 * It’s compared to the input  adc control port: ana_adc_chop. When different sar adc data  & sd adc data are twos complemented.  
 */
#define SIGP_CFG2_ACCEL_CHOP_PL_X_POS      0x00
#define SIGP_CFG2_ACCEL_CHOP_PL_X_MASK     0x01



/*
 * GYRO_TRIM1
 * Register Name : GYRO_TRIM1
 */

/*
 * gyro_drv_agc_on_delay 
 * When asserted, delayes the completion 
 * of the Gyro DRV Power up by 30 ms
 */
#define GYRO_TRIM1_GYRO_DRV_AGC_ON_DELAY_POS      0x03
#define GYRO_TRIM1_GYRO_DRV_AGC_ON_DELAY_MASK     (0x01 << GYRO_TRIM1_GYRO_DRV_AGC_ON_DELAY_POS)

/*
 * gyro_cp25v_off_delay 
 * Gyro charge pump; delay from gyro drive turning off to gyro charge pump turning off
 * 0: no delay
 * 1: 50 ms
 * 2:  100 ms
 * 3: 150 ms
 */
#define GYRO_TRIM1_GYRO_CP25V_OFF_DELAY_POS      0x00
#define GYRO_TRIM1_GYRO_CP25V_OFF_DELAY_MASK     0x03



/*
 * WUOSC_TRIM
 * Register Name : WUOSC_TRIM
 */

/*
 * wuosc_freq_trim_d2a 
 * Trimming of wake up osc frequency
 */
#define WUOSC_TRIM_WUOSC_FREQ_TRIM_D2A_POS      0x00
#define WUOSC_TRIM_WUOSC_FREQ_TRIM_D2A_MASK     0xff



/*
 * ANA_LAT_TRIM
 * Register Name : ANA_LAT_TRIM
 */

/*
 * gyro_ana_lat_trim_ind 
 * Gyro analog latency trimmed budget
 */
#define ANA_LAT_TRIM_GYRO_ANA_LAT_TRIM_IND_POS      0x06
#define ANA_LAT_TRIM_GYRO_ANA_LAT_TRIM_IND_MASK     (0x03 << ANA_LAT_TRIM_GYRO_ANA_LAT_TRIM_IND_POS)

/*
 * accel_ana_half_lpf_bw_lat_trim_ind 
 * Accel analog latency trimmed budget used when half bandwidth is selected for analog LPF
 */
#define ANA_LAT_TRIM_ACCEL_ANA_HALF_LPF_BW_LAT_TRIM_IND_POS      0x03
#define ANA_LAT_TRIM_ACCEL_ANA_HALF_LPF_BW_LAT_TRIM_IND_MASK     (0x07 << ANA_LAT_TRIM_ACCEL_ANA_HALF_LPF_BW_LAT_TRIM_IND_POS)

/*
 * accel_ana_full_lpf_bw_lat_trim_ind 
 * Accel analog latency trimmed budget used when full bandwidth is selected for analog LPF
 */
#define ANA_LAT_TRIM_ACCEL_ANA_FULL_LPF_BW_LAT_TRIM_IND_POS      0x00
#define ANA_LAT_TRIM_ACCEL_ANA_FULL_LPF_BW_LAT_TRIM_IND_MASK     0x07



/*
 * MISC_2
 * Register Name : MISC_2
 */

/*
 * sigp_mem_init_done_force 
 *  When high: if forces Sensor Shared Memory to re-initialise with POR default values.
 */
#define MISC_2_SIGP_MEM_INIT_DONE_FORCE_POS      0x00
#define MISC_2_SIGP_MEM_INIT_DONE_FORCE_MASK     0x01



/*
 * TESTMUX_SEL
 * Register Name : TESTMUX_SEL
 */

/*
 * tmux_sel 
 * This 8-bit register field is used to select dtp (digital test point) signals on test points, pad selection and test enables. 
 * 0x00: test modes disabled
 * 0x01-0x93: output mux enabled; dtp_out 4-bit signal group selection from different internal digital modules; refer to xian_test_mode.xlsx document, dig_core sheet for further details
 * 0x94-F2: test modes disabled
 * 0xF3: Digital signal path test enable
 * 0xF4: Digital test accel debug enable
 * 0xF5: Digital test gyro debug enable
 * 0xF6-0xF9: External clock source selection from dtp
 * 0xFA-0xFF: IO test pad selection
 */
#define TESTMUX_SEL_TMUX_SEL_POS      0x00
#define TESTMUX_SEL_TMUX_SEL_MASK     0xff



/*
 * ADI_0
 * Register Name : ADI_0
 */

/*
 * ovrd_pd_mbcore_bg_stup_bias_b_d2a 
 * nan
 */
#define ADI_0_OVRD_PD_MBCORE_BG_STUP_BIAS_B_D2A_POS      0x07
#define ADI_0_OVRD_PD_MBCORE_BG_STUP_BIAS_B_D2A_MASK     (0x01 << ADI_0_OVRD_PD_MBCORE_BG_STUP_BIAS_B_D2A_POS)

/*
 * ovrd_set_mbcore_vreg_service_d2a 
 * nan
 */
#define ADI_0_OVRD_SET_MBCORE_VREG_SERVICE_D2A_POS      0x06
#define ADI_0_OVRD_SET_MBCORE_VREG_SERVICE_D2A_MASK     (0x01 << ADI_0_OVRD_SET_MBCORE_VREG_SERVICE_D2A_POS)

/*
 * set_mbcore_vreg_service_d2a 
 * nan
 */
#define ADI_0_SET_MBCORE_VREG_SERVICE_D2A_POS      0x05
#define ADI_0_SET_MBCORE_VREG_SERVICE_D2A_MASK     (0x01 << ADI_0_SET_MBCORE_VREG_SERVICE_D2A_POS)

/*
 * en_rctrim_resmeas_d2a 
 * nan
 */
#define ADI_0_EN_RCTRIM_RESMEAS_D2A_POS      0x04
#define ADI_0_EN_RCTRIM_RESMEAS_D2A_MASK     (0x01 << ADI_0_EN_RCTRIM_RESMEAS_D2A_POS)

/*
 * en_rctrim_res_serp_meas_d2a 
 * nan
 */
#define ADI_0_EN_RCTRIM_RES_SERP_MEAS_D2A_POS      0x03
#define ADI_0_EN_RCTRIM_RES_SERP_MEAS_D2A_MASK     (0x01 << ADI_0_EN_RCTRIM_RES_SERP_MEAS_D2A_POS)

/*
 * en_rctrim_capmeas_d2a 
 * nan
 */
#define ADI_0_EN_RCTRIM_CAPMEAS_D2A_POS      0x02
#define ADI_0_EN_RCTRIM_CAPMEAS_D2A_MASK     (0x01 << ADI_0_EN_RCTRIM_CAPMEAS_D2A_POS)

/*
 * bg_stup_rc_b_d2a 
 * nan
 */
#define ADI_0_BG_STUP_RC_B_D2A_POS      0x01
#define ADI_0_BG_STUP_RC_B_D2A_MASK     (0x01 << ADI_0_BG_STUP_RC_B_D2A_POS)

/*
 * accel_aaf_lpf_d2a 
 * 0: Configure AAF LPF filter to Full BW (4.5KHz, effective 1.5 KHz for RR)
 * 1: Configure AAF LPF filter to Half BW (2.1KHz, effective 700 Hz for RR)
 * Note: If Half BW is selected, changing from LNM to LPM back and forth will imply automatic switch from half BW to full BW. This could generate a glitch on the data output when going from LPM to LNM. Therefore, for proper LPM to LNM operations, we recommend to only use Full BW.
 */
#define ADI_0_ACCEL_AAF_LPF_D2A_POS      0x00
#define ADI_0_ACCEL_AAF_LPF_D2A_MASK     0x01



/*
 * ADI_1
 * Register Name : ADI_1
 */

/*
 * pd_mbcore_bg_b_d2a 
 * nan
 */
#define ADI_1_PD_MBCORE_BG_B_D2A_POS      0x07
#define ADI_1_PD_MBCORE_BG_B_D2A_MASK     (0x01 << ADI_1_PD_MBCORE_BG_B_D2A_POS)

/*
 * pd_mbcore_areg_b_d2a 
 * nan
 */
#define ADI_1_PD_MBCORE_AREG_B_D2A_POS      0x06
#define ADI_1_PD_MBCORE_AREG_B_D2A_MASK     (0x01 << ADI_1_PD_MBCORE_AREG_B_D2A_POS)

/*
 * pd_accel_st_reg_b_d2a 
 * nan
 */
#define ADI_1_PD_ACCEL_ST_REG_B_D2A_POS      0x05
#define ADI_1_PD_ACCEL_ST_REG_B_D2A_MASK     (0x01 << ADI_1_PD_ACCEL_ST_REG_B_D2A_POS)

/*
 * pd_accel_cp3v_only_b_d2a 
 * nan
 */
#define ADI_1_PD_ACCEL_CP3V_ONLY_B_D2A_POS      0x04
#define ADI_1_PD_ACCEL_CP3V_ONLY_B_D2A_MASK     (0x01 << ADI_1_PD_ACCEL_CP3V_ONLY_B_D2A_POS)

/*
 * ovrd_sel_vref_swco_d2a 
 * nan
 */
#define ADI_1_OVRD_SEL_VREF_SWCO_D2A_POS      0x03
#define ADI_1_OVRD_SEL_VREF_SWCO_D2A_MASK     (0x01 << ADI_1_OVRD_SEL_VREF_SWCO_D2A_POS)

/*
 * ovrd_sel_vref_swco2_d2a 
 * nan
 */
#define ADI_1_OVRD_SEL_VREF_SWCO2_D2A_POS      0x02
#define ADI_1_OVRD_SEL_VREF_SWCO2_D2A_MASK     (0x01 << ADI_1_OVRD_SEL_VREF_SWCO2_D2A_POS)

/*
 * ovrd_sel_vref_swco1_d2a 
 * nan
 */
#define ADI_1_OVRD_SEL_VREF_SWCO1_D2A_POS      0x01
#define ADI_1_OVRD_SEL_VREF_SWCO1_D2A_MASK     (0x01 << ADI_1_OVRD_SEL_VREF_SWCO1_D2A_POS)

/*
 * ovrd_sel_temp_ibias_d2a 
 * nan
 */
#define ADI_1_OVRD_SEL_TEMP_IBIAS_D2A_POS      0x00
#define ADI_1_OVRD_SEL_TEMP_IBIAS_D2A_MASK     0x01



/*
 * ADI_2
 * Register Name : ADI_2
 */

/*
 * sel_vref_swco_d2a 
 * nan
 */
#define ADI_2_SEL_VREF_SWCO_D2A_POS      0x07
#define ADI_2_SEL_VREF_SWCO_D2A_MASK     (0x01 << ADI_2_SEL_VREF_SWCO_D2A_POS)

/*
 * sel_vref_swco2_d2a 
 * nan
 */
#define ADI_2_SEL_VREF_SWCO2_D2A_POS      0x06
#define ADI_2_SEL_VREF_SWCO2_D2A_MASK     (0x01 << ADI_2_SEL_VREF_SWCO2_D2A_POS)

/*
 * sel_vref_swco1_d2a 
 * nan
 */
#define ADI_2_SEL_VREF_SWCO1_D2A_POS      0x05
#define ADI_2_SEL_VREF_SWCO1_D2A_MASK     (0x01 << ADI_2_SEL_VREF_SWCO1_D2A_POS)

/*
 * sel_temp_ibias_d2a 
 * nan
 */
#define ADI_2_SEL_TEMP_IBIAS_D2A_POS      0x04
#define ADI_2_SEL_TEMP_IBIAS_D2A_MASK     (0x01 << ADI_2_SEL_TEMP_IBIAS_D2A_POS)

/*
 * pd_mbcore_vreg_service_b_d2a 
 * nan
 */
#define ADI_2_PD_MBCORE_VREG_SERVICE_B_D2A_POS      0x03
#define ADI_2_PD_MBCORE_VREG_SERVICE_B_D2A_MASK     (0x01 << ADI_2_PD_MBCORE_VREG_SERVICE_B_D2A_POS)

/*
 * pd_mbcore_vin_cp_1p6v_b_d2a 
 * nan
 */
#define ADI_2_PD_MBCORE_VIN_CP_1P6V_B_D2A_POS      0x02
#define ADI_2_PD_MBCORE_VIN_CP_1P6V_B_D2A_MASK     (0x01 << ADI_2_PD_MBCORE_VIN_CP_1P6V_B_D2A_POS)

/*
 * pd_mbcore_rctrim_b_d2a 
 * nan
 */
#define ADI_2_PD_MBCORE_RCTRIM_B_D2A_POS      0x01
#define ADI_2_PD_MBCORE_RCTRIM_B_D2A_MASK     (0x01 << ADI_2_PD_MBCORE_RCTRIM_B_D2A_POS)

/*
 * pd_mbcore_bg_stup_bias_b_d2a 
 * nan
 */
#define ADI_2_PD_MBCORE_BG_STUP_BIAS_B_D2A_POS      0x00
#define ADI_2_PD_MBCORE_BG_STUP_BIAS_B_D2A_MASK     0x01



/*
 * ADI_3
 * Register Name : ADI_3
 */

/*
 * vreg_service_rdy_d2a 
 * nan
 */
#define ADI_3_VREG_SERVICE_RDY_D2A_POS      0x00
#define ADI_3_VREG_SERVICE_RDY_D2A_MASK     0x01



/*
 * OTP_BNK4
 * Register Name : OTP_BNK4
 */

/*
 * otp_bnk4_placeholder 
 * Useless waste of 1byte location and 1flop just to allocate one Byte to OTP Bank4 to reuse OTP IP as it is
 */
#define OTP_BNK4_OTP_BNK4_PLACEHOLDER_POS      0x00
#define OTP_BNK4_OTP_BNK4_PLACEHOLDER_MASK     0x01



/*
 * APEX_CONFIG13
 * Register Name : APEX_CONFIG13
 */

/*
 * patch_pedometer 
 * If this bit is set and pedometer is enabled, DMP jumps to DMP SRAM@258 instead of executing pedometer algo. Note : it is patch code responsibility to jump back to ROM if needed.
 */
#define APEX_CONFIG13_PATCH_PEDOMETER_POS      0x01
#define APEX_CONFIG13_PATCH_PEDOMETER_MASK     (0x01 << APEX_CONFIG13_PATCH_PEDOMETER_POS)

/*
 * patch_freefall 
 * If this bit is set and freefall is enabled, DMP jumps to DMP SRAM@256 instead of executing Freefall algo. Note : it is patch code responsibility to jump back to ROM if needed.
 */
#define APEX_CONFIG13_PATCH_FREEFALL_POS      0x00
#define APEX_CONFIG13_PATCH_FREEFALL_MASK     0x01


/* ---------------------------------------------------------------------------
 * register MMEM_TOP
 * ---------------------------------------------------------------------------*/
/* ---------------------------------------------------------------------------
 * register MREG_OTP
 * ---------------------------------------------------------------------------*/

/*
 * OTP_CTRL3
 * Register Name : OTP_CTRL3
 */

/*
 * otp_mra 
 * otp auxiliary mode register, the is a 16-bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then program bit[15:8] for the programming to take effect.
 */
#define OTP_CTRL3_OTP_MRA_POS      0x00
#define OTP_CTRL3_OTP_MRA_MASK     0xff



/*
 * OTP_CTRL4
 * Register Name : OTP_CTRL4
 */

/*
 * otp_mra 
 * otp auxiliary mode register, the is a 16-bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then program bit[15:8] for the programming to take effect.
 */
#define OTP_CTRL4_OTP_MRA_POS      0x00
#define OTP_CTRL4_OTP_MRA_MASK     0xff



/*
 * OTP_CTRL5
 * Register Name : OTP_CTRL5
 */

/*
 * otp_mrb 
 * otp auxiliary mode register, the is a 16-bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then program bit[15:8] for thje programming to take effect.
 */
#define OTP_CTRL5_OTP_MRB_POS      0x00
#define OTP_CTRL5_OTP_MRB_MASK     0xff



/*
 * OTP_CTRL6
 * Register Name : OTP_CTRL6
 */

/*
 * otp_mrb 
 * otp auxiliary mode register, the is a 16-bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then program bit[15:8] for thje programming to take effect.
 */
#define OTP_CTRL6_OTP_MRB_POS      0x00
#define OTP_CTRL6_OTP_MRB_MASK     0xff



/*
 * OTP_CTRL1
 * Register Name : OTP_CTRL1
 */

/*
 * otp_mr 
 * otp mode register, this is a 16- bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then bit[15:8] for the programming to take effect.
 */
#define OTP_CTRL1_OTP_MR_POS      0x00
#define OTP_CTRL1_OTP_MR_MASK     0xff



/*
 * OTP_CTRL2
 * Register Name : OTP_CTRL2
 */

/*
 * otp_mr 
 * otp mode register, this is a 16- bit register. All 16-bit need to be programmed. Host need to program bit[7:0] first and then bit[15:8] for the programming to take effect.
 */
#define OTP_CTRL2_OTP_MR_POS      0x00
#define OTP_CTRL2_OTP_MR_MASK     0xff



/*
 * OTP_CTRL7
 * Register Name : OTP_CTRL7
 */

/*
 * pgm_dly_cfg 
 * One of the three selection bits for the PGM and SOAK pulse widths.
 */
#define OTP_CTRL7_PGM_DLY_CFG_POS      0x07
#define OTP_CTRL7_PGM_DLY_CFG_MASK     (0x01 << OTP_CTRL7_PGM_DLY_CFG_POS)

/*
 * otp_reset 
 * 1: to reset OTP macro. This bit is cleared to 0 after OTP reset is done.
 */
#define OTP_CTRL7_OTP_RESET_POS      0x06
#define OTP_CTRL7_OTP_RESET_MASK     (0x01 << OTP_CTRL7_OTP_RESET_POS)

/*
 * otp_stress 
 * 1: will double the read pulse width, this is required by stress test.
 */
#define OTP_CTRL7_OTP_STRESS_POS      0x05
#define OTP_CTRL7_OTP_STRESS_MASK     (0x01 << OTP_CTRL7_OTP_STRESS_POS)

/*
 * otp_boot 
 * 1: to allow user to access OTP macro boot block space.
 */
#define OTP_CTRL7_OTP_BOOT_POS      0x04
#define OTP_CTRL7_OTP_BOOT_MASK     (0x01 << OTP_CTRL7_OTP_BOOT_POS)

/*
 * otp_low_pwr_mode 
 * Low power mode, control VREF=VREFEXT switch. When LPM=0, internal power supply is enabled and internal read reference voltage is internally generated. When LPM=1, internal power supply is bypassed and internal read voltage is supplied by VREFEXT. When program or read in single-end mode, this bit should be 0.
 */
#define OTP_CTRL7_OTP_LOW_PWR_MODE_POS      0x02
#define OTP_CTRL7_OTP_LOW_PWR_MODE_MASK     (0x01 << OTP_CTRL7_OTP_LOW_PWR_MODE_POS)

/*
 * otp_soak 
 * 1: to extend program pulse from 150us to 500us.
 */
#define OTP_CTRL7_OTP_SOAK_POS      0x00
#define OTP_CTRL7_OTP_SOAK_MASK     0x01


/* ---------------------------------------------------------------------------
 * register MREG_FPGA
 * ---------------------------------------------------------------------------*/

/*
 * MSTR_SPI_CTRL
 * Register Name : MSTR_SPI_CTRL
 */

/*
 * mstr_spi_rst 
 * Reset the Master SPI. 0 : No action. 1 : Reset the Master SPI module. The bit must be manually cleared after a minimum delay of 100 ns.
 */
#define MSTR_SPI_CTRL_MSTR_SPI_RST_POS      0x00
#define MSTR_SPI_CTRL_MSTR_SPI_RST_MASK     0x01

/*
 * sent_to_slave 
 * Execute a Master SPI transaction to send/receive data to/from the sensor when in indirect mode (see indirect_access_en field). 0 : No action. 1 : Execute the transaction with address specified in register MSTR_SPI_ADDR and data specified in registers MSTR_SPI_WR_DATA. In case of a read transaction, the data from slave are read from register MSTR_SPI_RD_DATA
 */
#define MSTR_SPI_CTRL_SENT_TO_SLAVE_POS      0x01
#define MSTR_SPI_CTRL_SENT_TO_SLAVE_MASK     (0x01 << MSTR_SPI_CTRL_SENT_TO_SLAVE_POS)

/*
 * mstr_spi_freql 
 * Configure the Master SPI SCLK clock frequency. 0d : 10MHz, 1d : 5MHz, 2d : 3.33MHz, 3d : 2.5MHz, 4d : 2MHz, 5d : 1.66MHz, 6d : 1.42MHz, 7d : 1.25MHz
 */
#define MSTR_SPI_CTRL_MSTR_SPI_FREQL_POS      0x02
#define MSTR_SPI_CTRL_MSTR_SPI_FREQL_MASK     (0x07 << MSTR_SPI_CTRL_MSTR_SPI_FREQL_POS)

/*
 * indirect_access_en 
 * Selects between direct/indirect access to Master SPI. 0 : Direct mode. Maste SPI send/receive data specified by the reader controller. 1 : Indirect mode. Master SPI send/receive data coming from the Register Map, thus it can be programmed through the Slave SPI
 */
#define MSTR_SPI_CTRL_INDIRECT_ACCESS_EN_POS      0x05
#define MSTR_SPI_CTRL_INDIRECT_ACCESS_EN_MASK     (0x01 << MSTR_SPI_CTRL_INDIRECT_ACCESS_EN_POS)



/*
 * MSTR_SPI_ADDR
 * Register Name : MSTR_SPI_ADDR
 */

/*
 * mstr_spi_addr 
 * Address of the Master SPI transaction in indirect mode.
 */
#define MSTR_SPI_ADDR_MSTR_SPI_ADDR_POS      0x00
#define MSTR_SPI_ADDR_MSTR_SPI_ADDR_MASK     0xff



/*
 * MSTR_SPI_WR_DATA
 * Register Name : MSTR_SPI_WR_DATA
 */

/*
 * mstr_spi_wr_data 
 * Write data of the Master SPI transaction in indirect mode
 */
#define MSTR_SPI_WR_DATA_MSTR_SPI_WR_DATA_POS      0x00
#define MSTR_SPI_WR_DATA_MSTR_SPI_WR_DATA_MASK     0xff



/*
 * MSTR_SPI_RD_DATA
 * Register Name : MSTR_SPI_RD_DATA
 */

/*
 * mstr_spi_rd_data 
 * Read data of the Master SPI transaction in indirect mode ; default value 0xa5(d'165) indicates that master SPI is ready to get the data from sensor
 */
#define MSTR_SPI_RD_DATA_MSTR_SPI_RD_DATA_POS      0x00
#define MSTR_SPI_RD_DATA_MSTR_SPI_RD_DATA_MASK     0xff



/*
 * MSTR_SPI_STATUS
 * Register Name : MSTR_SPI_STATUS
 */

/*
 * mstr_spi_idle 
 * State of the Master SPI in indirect mode. Read-only bit. 0 : Master SPI is running. 1 : Master SPI is idle.
 */
#define MSTR_SPI_STATUS_MSTR_SPI_IDLE_POS      0x00
#define MSTR_SPI_STATUS_MSTR_SPI_IDLE_MASK     0x01

/*
 * mstr_spi_done 
 * State of the Master SPI transaction in indirect mode. Read-only bit. 0 : Transaction is running. 1 : Transaction not started yet or finished.
 */
#define MSTR_SPI_STATUS_MSTR_SPI_DONE_POS      0x01
#define MSTR_SPI_STATUS_MSTR_SPI_DONE_MASK     (0x01 << MSTR_SPI_STATUS_MSTR_SPI_DONE_POS)



/*
 * SENSOR_DATA_CTRL
 * Register Name : SENSOR_DATA_CTRL
 */

/*
 * start_sensor 
 * Starts the generation of external sensor data. 0 : Stop data generation. 1 : Start data generation.
 */
#define SENSOR_DATA_CTRL_START_SENSOR_POS      0x00
#define SENSOR_DATA_CTRL_START_SENSOR_MASK     0x01

/*
 * prologue_en 
 * Selects if the initialization commands to external sensor are provided. 0 : the initialization commands are not provided. 1 : the initialization commands are provided.
 */
#define SENSOR_DATA_CTRL_PROLOGUE_EN_POS      0x01
#define SENSOR_DATA_CTRL_PROLOGUE_EN_MASK     (0x01 << SENSOR_DATA_CTRL_PROLOGUE_EN_POS)

/*
 * acc_sensor_data_en 
 * Selects between Sine Waveform Generator and External Sensor accelero data. 0 : Sine Waveform Generator generates accelero data. 1 : External Sensor generates accelero data.
 */
#define SENSOR_DATA_CTRL_ACC_SENSOR_DATA_EN_POS      0x02
#define SENSOR_DATA_CTRL_ACC_SENSOR_DATA_EN_MASK     (0x01 << SENSOR_DATA_CTRL_ACC_SENSOR_DATA_EN_POS)

/*
 * gyro_sensor_data_en 
 * Selects between Sine Waveform Generator and External Sensor gyro data. 0 : Sine Waveform Generator generates gyro data. 1 : External Sensor generates gyro data.
 */
#define SENSOR_DATA_CTRL_GYRO_SENSOR_DATA_EN_POS      0x03
#define SENSOR_DATA_CTRL_GYRO_SENSOR_DATA_EN_MASK     (0x01 << SENSOR_DATA_CTRL_GYRO_SENSOR_DATA_EN_POS)



/*
 * FPGA_ID
 * Register Name : FPGA_ID
 */

/*
 * fpga_id 
 * for Xian FPGA, id = 0x0c(d'12)
 */
#define FPGA_ID_FPGA_ID_POS      0x00
#define FPGA_ID_FPGA_ID_MASK     0xff



/*
 * FPGA_CONFIG
 * Register Name : FPGA_CONFIG
 */

/*
 * fpga_root_clk_sel 
 * Select the FPGA root clock frequency which correspond to the ASIC main clock PLL output. 0 : 20.48 MHz. 1 : 19.20 MHz.
 */
#define FPGA_CONFIG_FPGA_ROOT_CLK_SEL_POS      0x00
#define FPGA_CONFIG_FPGA_ROOT_CLK_SEL_MASK     0x01



/*
 * REVISION1
 * Register Name : REVISION1
 */

/*
 * fpga_major_revision 
 * Mayor revision number refers to project.
 */
#define REVISION1_FPGA_MAJOR_REVISION_POS      0x00
#define REVISION1_FPGA_MAJOR_REVISION_MASK     0xff



/*
 * REVISION2
 * Register Name : REVISION2
 */

/*
 * fpga_minor_revision 
 * Minor revision number refers to FPGA release. Release 1 =:  1. Release 2 =:  2.
 */
#define REVISION2_FPGA_MINOR_REVISION_POS      0x00
#define REVISION2_FPGA_MINOR_REVISION_MASK     0xff



/*
 * ACCEL_X_FRE
 * Register Name : ACCEL_X_FRE
 */

/*
 * accel_x_fre 
 * Accelerometer X axis input stimuli frequency selection. Depending on accel_clk_div[3:0] field and clock frequency Fclk (@ 4MHz). Fclk/2^(clk_div  [3:0]) ∙(1+accel_x_fre[7:0])/4096
 */
#define ACCEL_X_FRE_ACCEL_X_FRE_POS      0x00
#define ACCEL_X_FRE_ACCEL_X_FRE_MASK     0xff



/*
 * ACCEL_X_AMP
 * Register Name : ACCEL_X_AMP
 */

/*
 * accel_x_amp 
 * Accelerometer X axis input stimuli zero-to-peak linear amplitude selection in the range [0 gee : +40 gee[ (resolution 0.15625 gee). (accel_x_amp[7:0])/256∙40 gee
 */
#define ACCEL_X_AMP_ACCEL_X_AMP_POS      0x00
#define ACCEL_X_AMP_ACCEL_X_AMP_MASK     0xff



/*
 * ACCEL_X_OFS
 * Register Name : ACCEL_X_OFS
 */

/*
 * accel_x_ofs 
 * Accelerometer X axis input stimuli linear offset selection in the range [–40 gee : +40 gee[  (resolution 0.3125 gee) ($signed(accel_x_ofs[7:0]))/128∙40 gee
 */
#define ACCEL_X_OFS_ACCEL_X_OFS_POS      0x00
#define ACCEL_X_OFS_ACCEL_X_OFS_MASK     0xff



/*
 * ACCEL_X_PHA
 * Register Name : ACCEL_X_PHA
 */

/*
 * accel_x_dith_en 
 * When high Accelerometer X axis dither is enabled on sinewave stimulus
 */
#define ACCEL_X_PHA_ACCEL_X_DITH_EN_POS      0x00
#define ACCEL_X_PHA_ACCEL_X_DITH_EN_MASK     0x01

/*
 * accel_x_pha 
 * Accelerometer X axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((accel_x_pha[6:0]))/128∙360 deg
 */
#define ACCEL_X_PHA_ACCEL_X_PHA_POS      0x01
#define ACCEL_X_PHA_ACCEL_X_PHA_MASK     (0x7f << ACCEL_X_PHA_ACCEL_X_PHA_POS)



/*
 * ACCEL_X_Y_AEX
 * Register Name : ACCEL_X_Y_AEX
 */

/*
 * accel_y_aex 
 * Accelerometer Y axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-accel_y_aex[3:0]) ( dB equivalence :     -6dB ∙accel_y_aex[3:0] )
 */
#define ACCEL_X_Y_AEX_ACCEL_Y_AEX_POS      0x00
#define ACCEL_X_Y_AEX_ACCEL_Y_AEX_MASK     0x0f

/*
 * accel_x_aex 
 * Accelerometer X axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-accel_x_aex[3:0])   ( dB equivalence :     -6dB ∙accel_x_aex[3:0] )
 */
#define ACCEL_X_Y_AEX_ACCEL_X_AEX_POS      0x04
#define ACCEL_X_Y_AEX_ACCEL_X_AEX_MASK     (0x0f << ACCEL_X_Y_AEX_ACCEL_X_AEX_POS)



/*
 * ACCEL_Y_FRE
 * Register Name : ACCEL_Y_FRE
 */

/*
 * accel_y_fre 
 * Accelerometer Y axis input stimuli frequency selection. Depending on accel_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+accel_y_fre[7:0])/4096
 */
#define ACCEL_Y_FRE_ACCEL_Y_FRE_POS      0x00
#define ACCEL_Y_FRE_ACCEL_Y_FRE_MASK     0xff



/*
 * ACCEL_Y_AMP
 * Register Name : ACCEL_Y_AMP
 */

/*
 * accel_y_amp 
 * Accelerometer Y axis input stimuli zero-to-peak linear amplitude selection in the range [0 gee : +40 gee[  (resolution 0.15625 gee)(accel_y_amp[7:0])/256∙40 gee
 */
#define ACCEL_Y_AMP_ACCEL_Y_AMP_POS      0x00
#define ACCEL_Y_AMP_ACCEL_Y_AMP_MASK     0xff



/*
 * ACCEL_Y_OFS
 * Register Name : ACCEL_Y_OFS
 */

/*
 * accel_y_ofs 
 * Accelerometer Y axis input stimuli linear offset selection in the range [–40 gee : +40 gee[  (resolution 0.3125 gee)($signed(accel_y_ofs[7:0]))/128∙40 gee
 */
#define ACCEL_Y_OFS_ACCEL_Y_OFS_POS      0x00
#define ACCEL_Y_OFS_ACCEL_Y_OFS_MASK     0xff



/*
 * ACCEL_Y_PHA
 * Register Name : ACCEL_Y_PHA
 */

/*
 * accel_y_dith_en 
 * When high Accelerometer Y axis dither is enabled on sinewave stimulus
 */
#define ACCEL_Y_PHA_ACCEL_Y_DITH_EN_POS      0x00
#define ACCEL_Y_PHA_ACCEL_Y_DITH_EN_MASK     0x01

/*
 * accel_y_pha 
 * Accelerometer Y axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((accel_y_pha[6:0]))/128∙360 deg
 */
#define ACCEL_Y_PHA_ACCEL_Y_PHA_POS      0x01
#define ACCEL_Y_PHA_ACCEL_Y_PHA_MASK     (0x7f << ACCEL_Y_PHA_ACCEL_Y_PHA_POS)



/*
 * ACCEL_Z_FRE
 * Register Name : ACCEL_Z_FRE
 */

/*
 * accel_z_fre 
 * Accelerometer Z axis input stimuli frequency selection. Depending on accel_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+accel_z_fre[7:0])/4096
 */
#define ACCEL_Z_FRE_ACCEL_Z_FRE_POS      0x00
#define ACCEL_Z_FRE_ACCEL_Z_FRE_MASK     0xff



/*
 * ACCEL_Z_AMP
 * Register Name : ACCEL_Z_AMP
 */

/*
 * accel_z_amp 
 * Accelerometer Z axis input stimuli zero-to-peak linear amplitude selection in the range [0 gee : +40 gee[  (resolution 0.15625 gee) (accel_z_amp[7:0])/256∙40 gee
 */
#define ACCEL_Z_AMP_ACCEL_Z_AMP_POS      0x00
#define ACCEL_Z_AMP_ACCEL_Z_AMP_MASK     0xff



/*
 * ACCEL_Z_OFS
 * Register Name : ACCEL_Z_OFS
 */

/*
 * accel_z_ofs 
 * Accelerometer Z axis input stimuli linear offset selection in the range [–40 gee : +40 gee[  (resolution 0.3125 gee) ($signed(accel_z_ofs[7:0]))/128∙40 gee
 */
#define ACCEL_Z_OFS_ACCEL_Z_OFS_POS      0x00
#define ACCEL_Z_OFS_ACCEL_Z_OFS_MASK     0xff



/*
 * ACCEL_Z_PHA
 * Register Name : ACCEL_Z_PHA
 */

/*
 * accel_z_dith_en 
 * When high Accelerometer Z axis dither is enabled on sinewave stimulus
 */
#define ACCEL_Z_PHA_ACCEL_Z_DITH_EN_POS      0x00
#define ACCEL_Z_PHA_ACCEL_Z_DITH_EN_MASK     0x01

/*
 * accel_z_pha 
 * Accelerometer Z axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((accel_z_pha[6:0]))/128∙360 deg
 */
#define ACCEL_Z_PHA_ACCEL_Z_PHA_POS      0x01
#define ACCEL_Z_PHA_ACCEL_Z_PHA_MASK     (0x7f << ACCEL_Z_PHA_ACCEL_Z_PHA_POS)



/*
 * ACCEL_Z_GYRO_X_AEX
 * Register Name : ACCEL_Z_GYRO_X_AEX
 */

/*
 * gyro_x_aex 
 * Gyroscope X axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-gyro_x_aex[3:0])   ( dB equivalence :     -6dB ∙gyro_x_aex[3:0] )
 */
#define ACCEL_Z_GYRO_X_AEX_GYRO_X_AEX_POS      0x00
#define ACCEL_Z_GYRO_X_AEX_GYRO_X_AEX_MASK     0x0f

/*
 * accel_z_aex 
 * Accelerometer Z axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-accel_z_aex[3:0])   ( dB equivalence :     -6dB ∙accel_z_aex[3:0] )
 */
#define ACCEL_Z_GYRO_X_AEX_ACCEL_Z_AEX_POS      0x04
#define ACCEL_Z_GYRO_X_AEX_ACCEL_Z_AEX_MASK     (0x0f << ACCEL_Z_GYRO_X_AEX_ACCEL_Z_AEX_POS)



/*
 * GYRO_X_FRE
 * Register Name : GYRO_X_FRE
 */

/*
 * gyro_x_fre 
 * Gyroscope X axis input stimuli frequency selection. Depending on gyro_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+gyro_x_fre[7:0])/4096
 */
#define GYRO_X_FRE_GYRO_X_FRE_POS      0x00
#define GYRO_X_FRE_GYRO_X_FRE_MASK     0xff



/*
 * GYRO_X_AMP
 * Register Name : GYRO_X_AMP
 */

/*
 * gyro_x_amp 
 * Gyroscope X axis input stimuli zero-to-peak linear amplitude selection in the range [0 dps : +3000 dps[  (resolution 11.71875 dps) (gyro_x_amp[7:0])/256∙3000 dps
 */
#define GYRO_X_AMP_GYRO_X_AMP_POS      0x00
#define GYRO_X_AMP_GYRO_X_AMP_MASK     0xff



/*
 * GYRO_X_OFS
 * Register Name : GYRO_X_OFS
 */

/*
 * gyro_x_ofs 
 * Gyroscope X axis input stimuli linear offset selection in the range [–3000 dps: +3000 dps [  (resolution 23.4375 dps)($signed(gyro_x_ofs[7:0]))/128∙3000 dps
 */
#define GYRO_X_OFS_GYRO_X_OFS_POS      0x00
#define GYRO_X_OFS_GYRO_X_OFS_MASK     0xff



/*
 * GYRO_X_PHA
 * Register Name : GYRO_X_PHA
 */

/*
 * gyro_x_dith_en 
 * When high Gyroscope X axis dither is enabled on sinewave stimulus
 */
#define GYRO_X_PHA_GYRO_X_DITH_EN_POS      0x00
#define GYRO_X_PHA_GYRO_X_DITH_EN_MASK     0x01

/*
 * gyro_x_pha 
 * Gyroscope X axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((gyro_x_pha[6:0]))/128∙360 deg
 */
#define GYRO_X_PHA_GYRO_X_PHA_POS      0x01
#define GYRO_X_PHA_GYRO_X_PHA_MASK     (0x7f << GYRO_X_PHA_GYRO_X_PHA_POS)



/*
 * GYRO_Y_FRE
 * Register Name : GYRO_Y_FRE
 */

/*
 * gyro_y_fre 
 * Gyroscope Y axis input stimuli frequency selection. Depending on gyro_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+gyro_y_fre[7:0])/4096
 */
#define GYRO_Y_FRE_GYRO_Y_FRE_POS      0x00
#define GYRO_Y_FRE_GYRO_Y_FRE_MASK     0xff



/*
 * GYRO_Y_AMP
 * Register Name : GYRO_Y_AMP
 */

/*
 * gyro_y_amp 
 * Gyroscope Y axis input stimuli zero-to-peak linear amplitude selection in the range [0 dps : +3000 dps[  (resolution 11.71875 dps) (gyro_y_amp[7:0])/256∙3000 dps
 */
#define GYRO_Y_AMP_GYRO_Y_AMP_POS      0x00
#define GYRO_Y_AMP_GYRO_Y_AMP_MASK     0xff



/*
 * GYRO_Y_OFS
 * Register Name : GYRO_Y_OFS
 */

/*
 * gyro_y_ofs 
 * Gyroscope Y axis input stimuli linear offset selection in the range [–3000 dps: +3000 dps [  (resolution 23.4375 dps)($signed(gyro_y_ofs[7:0]))/128∙3000 dps
 */
#define GYRO_Y_OFS_GYRO_Y_OFS_POS      0x00
#define GYRO_Y_OFS_GYRO_Y_OFS_MASK     0xff



/*
 * GYRO_Y_PHA
 * Register Name : GYRO_Y_PHA
 */

/*
 * gyro_y_dith_en 
 * When high Gyroscope Y axis dither is enabled on sinewave stimulus
 */
#define GYRO_Y_PHA_GYRO_Y_DITH_EN_POS      0x00
#define GYRO_Y_PHA_GYRO_Y_DITH_EN_MASK     0x01

/*
 * gyro_y_pha 
 * Gyroscope Y axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg) ((gyro_y_pha[6:0]))/128∙360 deg
 */
#define GYRO_Y_PHA_GYRO_Y_PHA_POS      0x01
#define GYRO_Y_PHA_GYRO_Y_PHA_MASK     (0x7f << GYRO_Y_PHA_GYRO_Y_PHA_POS)



/*
 * GYRO_Y_GYRO_Z_AEX
 * Register Name : GYRO_Y_GYRO_Z_AEX
 */

/*
 * gyro_z_aex 
 * Gyroscope Z axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-gyro_z_aex[3:0])   ( dB equivalence :     -6dB ∙gyro_z_aex[3:0] )
 */
#define GYRO_Y_GYRO_Z_AEX_GYRO_Z_AEX_POS      0x00
#define GYRO_Y_GYRO_Z_AEX_GYRO_Z_AEX_MASK     0x0f

/*
 * gyro_y_aex 
 * Gyroscope Y axis input stimuli exponential gain selection (multiplying the amplitude selection) = 2^(-gyro_y_aex[3:0])   ( dB equivalence :     -6dB ∙gyro_y_aex[3:0] )
 */
#define GYRO_Y_GYRO_Z_AEX_GYRO_Y_AEX_POS      0x04
#define GYRO_Y_GYRO_Z_AEX_GYRO_Y_AEX_MASK     (0x0f << GYRO_Y_GYRO_Z_AEX_GYRO_Y_AEX_POS)



/*
 * GYRO_Z_FRE
 * Register Name : GYRO_Z_FRE
 */

/*
 * gyro_z_fre 
 * Gyroscope Z axis input stimuli frequency selection. Depending on gyro_clk_div[3:0] field and clock frequency Fclk (@ 4MHz) = Fclk/2^(clk_div  [3:0]) ∙(1+gyro_z_fre[7:0])/4096
 */
#define GYRO_Z_FRE_GYRO_Z_FRE_POS      0x00
#define GYRO_Z_FRE_GYRO_Z_FRE_MASK     0xff



/*
 * GYRO_Z_AMP
 * Register Name : GYRO_Z_AMP
 */

/*
 * gyro_z_amp 
 * Gyroscope Z axis input stimuli zero-to-peak linear amplitude selection in the range [0 dps : +3000 dps[  (resolution 11.71875 dps) (gyro_z_amp[7:0])/256∙3000 dps
 */
#define GYRO_Z_AMP_GYRO_Z_AMP_POS      0x00
#define GYRO_Z_AMP_GYRO_Z_AMP_MASK     0xff



/*
 * GYRO_Z_OFS
 * Register Name : GYRO_Z_OFS
 */

/*
 * gyro_z_ofs 
 * Gyroscope Z axis input stimuli linear offset selection in the range [–3000 dps: +3000 dps [  (resolution 23.4375 dps)($signed(gyro_z_ofs[7:0]))/128∙3000 dps
 */
#define GYRO_Z_OFS_GYRO_Z_OFS_POS      0x00
#define GYRO_Z_OFS_GYRO_Z_OFS_MASK     0xff



/*
 * GYRO_Z_PHA
 * Register Name : GYRO_Z_PHA
 */

/*
 * gyro_z_dith_en 
 * When high Gyroscope Z axis dither is enabled on sinewave stimulus
 */
#define GYRO_Z_PHA_GYRO_Z_DITH_EN_POS      0x00
#define GYRO_Z_PHA_GYRO_Z_DITH_EN_MASK     0x01

/*
 * gyro_z_pha 
 * Gyroscope Z axis input stimuli linear phase selection in the range [0 deg : 360 deg[  (resolution 2.81 deg)((gyro_z_pha[6:0]))/128∙360 deg
 */
#define GYRO_Z_PHA_GYRO_Z_PHA_POS      0x01
#define GYRO_Z_PHA_GYRO_Z_PHA_MASK     (0x7f << GYRO_Z_PHA_GYRO_Z_PHA_POS)



/*
 * ACCEL_GRYO_CLKDIV
 * Register Name : ACCEL_GRYO_CLKDIV
 */

/*
 * gyro_clk_div 
 * Gyro sinwave generator clock frequency (Fclk @ 4MHz) divider. Impacting stimuli generated frequencies. Fclk/[2^(clk_div  [3:0])]
 */
#define ACCEL_GRYO_CLKDIV_GYRO_CLK_DIV_POS      0x00
#define ACCEL_GRYO_CLKDIV_GYRO_CLK_DIV_MASK     0x0f

/*
 * accel_clk_div 
 * Accelero sinwave generator clock frequency (Fclk @ 4MHz) divider. Impacting stimuli generated frequencies. Fclk/[2^(clk_div  [3:0])]
 */
#define ACCEL_GRYO_CLKDIV_ACCEL_CLK_DIV_POS      0x04
#define ACCEL_GRYO_CLKDIV_ACCEL_CLK_DIV_MASK     (0x0f << ACCEL_GRYO_CLKDIV_ACCEL_CLK_DIV_POS)



/*
 * FPGA_CTRL
 * Register Name : FPGA_CTRL
 */

/*
 * bram_wr_dis 
 * 1: to disable write access to BRAM.
 */
#define FPGA_CTRL_BRAM_WR_DIS_POS      0x00
#define FPGA_CTRL_BRAM_WR_DIS_MASK     0x01

/*
 * ram_ovf 
 * 1: means SRAM overflow error ever occurs.
 */
#define FPGA_CTRL_RAM_OVF_POS      0x01
#define FPGA_CTRL_RAM_OVF_MASK     (0x01 << FPGA_CTRL_RAM_OVF_POS)



/*
 * FPGA_REG0
 * Register Name : FPGA_REG0
 */

/*
 * fpga_dbg0 
 * debug registers
 */
#define FPGA_REG0_FPGA_DBG0_POS      0x00
#define FPGA_REG0_FPGA_DBG0_MASK     0xff



/*
 * FPGA_REG1
 * Register Name : FPGA_REG1
 */

/*
 * fpga_dbg1 
 * debug registers
 */
#define FPGA_REG1_FPGA_DBG1_POS      0x00
#define FPGA_REG1_FPGA_DBG1_MASK     0xff



/*
 * FPGA_REG2
 * Register Name : FPGA_REG2
 */

/*
 * fpga_dbg2 
 * debug registers
 */
#define FPGA_REG2_FPGA_DBG2_POS      0x00
#define FPGA_REG2_FPGA_DBG2_MASK     0xff



/*
 * FPGA_REG3
 * Register Name : FPGA_REG3
 */

/*
 * fpga_dbg3 
 * debug registers
 */
#define FPGA_REG3_FPGA_DBG3_POS      0x00
#define FPGA_REG3_FPGA_DBG3_MASK     0xff



/*
 * FPGA_REG4
 * Register Name : FPGA_REG4
 */

/*
 * fpga_dbg4 
 * debug registers
 */
#define FPGA_REG4_FPGA_DBG4_POS      0x00
#define FPGA_REG4_FPGA_DBG4_MASK     0xff



/*
 * FPGA_REG5
 * Register Name : FPGA_REG5
 */

/*
 * fpga_dbg5 
 * debug registers
 */
#define FPGA_REG5_FPGA_DBG5_POS      0x00
#define FPGA_REG5_FPGA_DBG5_MASK     0xff


/* ---------------------------------------------------------------------------
 * register ROM
 * ---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif  /*#ifndef _INV_IMU_REGMAP_INTERNAL_H_*/
