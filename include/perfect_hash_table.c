#include <stdint.h>
#define SIZE 899
#define DSIZE 224
int16_t  disambiguationTable[DSIZE]= {9,20,2,48,23,7,76,39,-820,14,2,83,2,1,17,7,3,21,4,-731,-729,-727,-725,8,6,503,11,-724,13,7,3,108,10,12,1,1,6,21,2,5,3,2,1,-708,46,29,31,7,3,29,21,18,156,3,13,1,47,4,0,2,400,9,174,28,91,52,86,29,157,105,5,21,205,1,46,4,42,2,1,24,161,27,27,109,37,59,-586,13,378,3,7,11,728,1,90,111,428,19,93,176,111,23,44,32,5,110,51,1,-571,3,490,759,9,1,-535,-507,25,27,-486,-401,2,1221,11,2,2,8,11,-348,122,304,166,535,84,296,-345,254,-295,50,3,12,190,0,330,3,279,141,10,124,115,629,44,2,11,49,-281,57,1297,24,60,40,50,-171,76,203,-37,145,350,616,93,1,187,601,116,7,1300,26,92,62,0,126,565,747,83,1038,88,5,4,420,146,1155,17,299,515,574,1615,9,368,1,5,85,17,102,0,79,4,1961,53,1,2233,-27,2,75,122,108,1,119,13,420,1124,1279,1893,472,12,2343};
uint16_t  table[SIZE]= {399,548,633,822,736,606,377,285,543,365,56,324,206,608,830,220,657,698,803,789,55,509,602,184,441,472,263,13,421,842,51,43,222,752,811,504,322,592,579,813,465,587,20,475,282,860,723,175,647,417,115,186,278,172,469,797,329,471,185,823,721,358,19,346,221,692,250,456,134,481,277,33,246,516,652,532,412,691,396,262,597,61,489,809,213,824,143,890,476,289,582,380,249,804,483,242,321,309,448,265,212,45,420,500,771,194,748,805,470,477,389,716,800,549,171,591,74,757,770,168,526,330,877,714,70,796,97,846,106,649,371,839,670,625,865,254,773,588,394,387,372,350,737,223,245,21,462,29,558,137,871,603,292,364,681,573,382,260,750,740,671,765,207,891,792,3,739,556,585,433,208,772,405,544,743,730,706,1,576,878,119,241,654,806,319,310,642,37,845,862,109,474,786,555,436,793,745,176,645,541,831,725,111,256,621,435,47,841,490,247,360,203,527,853,31,95,170,616,874,778,11,416,331,534,240,661,239,6,899,178,667,68,520,338,605,333,99,103,744,30,164,308,801,705,385,161,50,503,836,833,210,89,122,445,523,726,155,817,135,145,167,694,569,150,266,189,304,784,525,700,400,314,343,306,459,821,634,177,22,83,620,427,563,361,547,463,746,32,749,685,783,10,327,94,244,375,690,121,251,754,873,535,867,838,600,895,5,684,391,227,870,674,54,615,861,226,422,733,848,209,557,787,165,108,90,756,156,887,788,767,275,586,501,506,468,876,2,299,522,461,86,27,88,342,214,864,782,411,35,205,232,418,261,337,688,495,332,828,366,764,390,42,430,538,735,849,140,267,406,443,16,774,287,102,884,339,808,273,627,66,182,589,560,679,612,624,305,84,759,651,517,485,300,352,701,91,844,457,869,96,623,581,432,656,819,451,349,635,791,284,859,46,453,187,900,279,233,802,466,257,604,272,530,689,697,152,596,593,780,717,173,100,431,460,790,362,446,655,539,868,9,354,159,368,766,202,76,335,295,116,57,59,872,447,344,78,820,491,507,357,584,312,704,296,291,151,65,519,829,567,482,855,682,444,676,438,270,854,464,883,268,702,837,494,533,41,153,281,317,157,827,747,662,118,834,755,93,114,294,892,683,112,80,52,225,320,258,798,238,851,428,141,128,166,763,835,381,180,216,127,363,356,658,307,715,545,632,564,885,401,663,514,641,449,639,512,195,44,188,154,719,825,67,192,77,48,636,274,133,105,373,359,81,761,402,879,120,60,699,686,379,510,288,316,760,410,880,768,659,574,675,536,598,826,215,531,429,628,729,34,630,866,107,881,648,775,513,439,313,742,713,129,508,301,551,25,727,631,619,776,230,190,243,217,646,570,643,458,353,408,614,712,259,326,53,678,315,577,40,117,486,201,896,640,488,101,473,889,384,136,611,578,370,856,528,183,302,158,888,452,818,144,886,695,179,149,392,345,234,807,269,777,15,426,638,858,665,708,169,228,340,594,160,386,71,455,575,252,840,248,664,816,553,374,163,75,286,398,369,378,23,113,132,863,552,521,580,479,599,537,511,351,347,388,810,229,63,741,480,437,404,561,617,710,413,24,280,328,181,815,14,794,271,492,38,613,762,653,442,197,231,799,367,629,49,253,204,82,666,893,732,814,781,724,847,403,355,85,622,550,235,590,738,130,311,812,595,123,39,8,7,174,450,660,323,758,852,325,237,529,414,12,493,139,334,193,718,69,348,407,502,518,843,672,677,668,147,98,73,568,583,637,650,554,124,198,58,559,540,785,224,562,497,515,894,126,424,795,255,62,680,644,196,499,290,875,148,276,687,283,72,425,566,199,318,673,571,731,882,487,303,779,162,478,434,703,734,376,707,28,211,546,898,669,542,751,17,440,897,110,142,236,609,297,293,524,397,618,395,709,498,104,64,125,146,696,200,857,467,393,693,626,79,711,138,722,92,496,191,454,423,419,131,36,607,409,26,565,850,832,87,728,601,219,383,610,572,753,336,415,18,298,4,505,484,720,341,218,769};

uint32_t hashFunction(int16_t  d,int rhs[],int rhs_size){
	uint32_t c=(uint32_t)d;
	int i = 0;
	if(d==0) (c=0x01000193);
	for(i=0;i<rhs_size;i++) c =((c * 0x01000193)^rhs[i]) & 0xffffffff;
	return c;
}
 
uint16_t  lookUp(int rhs[],int rhs_size){
	int16_t  d = disambiguationTable[hashFunction(0,rhs,rhs_size)%DSIZE];
	if(d<0) return table[-d-1];
	return table[hashFunction(d,rhs,rhs_size)%SIZE];
}