/* pdp11_cr_dat.h
 *
 * card code arrays are indexed by 7-bit ASCII code, and
 * give corresponding 12-bit card codes using the indicated
 * collating sequence.
 *
 * ERROR should be externally defined, either as an illegal
 * card code (on conversion from ASCII to card codes) or as
 * a code with a bit set outside the least significant 12.
 *
 * author:  Douglas Jones, jones@cs.uiowa.edu
 * revisions:
 *      March 5, 1996
 *      Feb  18, 1997 to add 026 and EBCDIC converstion tables
 *      Jan 10, 2005, (JAD) Added 'static const' to the array
 *      definitions.
 *      Jan 11, 2005, (JAD) Create the h2c_code array.
 *      Jan 14, 2005, (JAD) Added the special DEC code for 'end of deck'
 *      (12-11-0-1-6-7-8-9) to the o29_code array at position 26. (^Z).
 *      Should I add this to the other arrays?
 *      Feb 24, 2007, (JGP) Added the DEC version of the 026 codepage and
 *      fixed some DEC029 codes.
 */

/* DEC's version of the IBM 029 kepunch encoding, (thus avoiding IBM's
   use of non-ASCII punctuation), based on that given in the appendix
   to Digital's "Small Computer Handbook, 1973", and augmented to
   translate lower case to upper case.  As a result of this modification,
   inversion of this table should be done with care! */
static const int o29_code[] = {
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* chars   */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control */
        ERROR,ERROR,07417,ERROR,ERROR,ERROR,ERROR,ERROR, /* chars   */
        00000,04006,00006,00102,02102,01042,04000,00022, /*  !"#$%&' */
        04022,02022,02042,04012,01102,02000,04102,01400, /* ()*+,-./ */
        01000,00400,00200,00100,00040,00020,00010,00004, /* 01234567 */
        00002,00001,00202,02012,04042,00012,01012,01006, /* 89:;<=>? */
        00042,04400,04200,04100,04040,04020,04010,04004, /* @ABCDEFG */
        04002,04001,02400,02200,02100,02040,02020,02010, /* HIJKLMNO */
        02004,02002,02001,01200,01100,01040,01020,01010, /* PQRSTUVW */
        01004,01002,01001,04202,02006,02202,04006,01022, /* XYZ[\]^_ */
        ERROR,04400,04200,04100,04040,04020,04010,04004, /* `abcdefg */
        04002,04001,02400,02200,02100,02040,02020,02010, /* hijklmno */
        02004,02002,02001,01200,01100,01040,01020,01010, /* pqrstuvw */
        01004,01002,01001,04000,ERROR,02000,ERROR,ERROR  /* xyz{|}~  */
    };

/* Bare bones 026 kepunch encodings */
static const int o26_ftn_code[] = {
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* chars   */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* chars   */
        00000,ERROR,ERROR,ERROR,02102,ERROR,ERROR,00042, /*  !"#$%&' */
        01042,04042,02042,04000,01102,02000,04102,01400, /* ()*+,-./ */
        01000,00400,00200,00100,00040,00020,00010,00004, /* 01234567 */
        00002,00001,ERROR,ERROR,ERROR,00102,ERROR,ERROR, /* 89:;<=>? */
        ERROR,04400,04200,04100,04040,04020,04010,04004, /* @ABCDEFG */
        04002,04001,02400,02200,02100,02040,02020,02010, /* HIJKLMNO */
        02004,02002,02001,01200,01100,01040,01020,01010, /* PQRSTUVW */
        01004,01002,01001,ERROR,ERROR,ERROR,ERROR,ERROR, /* XYZ[\]^_ */
        ERROR,04400,04200,04100,04040,04020,04010,04004, /* `abcdefg */
        04002,04001,02400,02200,02100,02040,02020,02010, /* hijklmno */
        02004,02002,02001,01200,01100,01040,01020,01010, /* pqrstuvw */
        01004,01002,01001,ERROR,ERROR,ERROR,ERROR,ERROR  /* xyz{|}~  */
    };

static const int o26_comm_code[] = {
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* chars   */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* chars   */
        00000,ERROR,ERROR,00102,02102,01042,04000,ERROR, /*  !"#$%&' */
        ERROR,ERROR,02042,ERROR,01102,02000,04102,01400, /* ()*+,-./ */
        01000,00400,00200,00100,00040,00020,00010,00004, /* 01234567 */
        00002,00001,ERROR,ERROR,04042,ERROR,ERROR,ERROR, /* 89:;<=>? */
        00042,04400,04200,04100,04040,04020,04010,04004, /* @ABCDEFG */
        04002,04001,02400,02200,02100,02040,02020,02010, /* HIJKLMNO */
        02004,02002,02001,01200,01100,01040,01020,01010, /* PQRSTUVW */
        01004,01002,01001,ERROR,ERROR,ERROR,ERROR,ERROR, /* XYZ[\]^_ */
        ERROR,04400,04200,04100,04040,04020,04010,04004, /* `abcdefg */
        04002,04001,02400,02200,02100,02040,02020,02010, /* hijklmno */
        02004,02002,02001,01200,01100,01040,01020,01010, /* pqrstuvw */
        01004,01002,01001,ERROR,ERROR,ERROR,ERROR,ERROR  /* xyz{|}~  */
    };

/* 026DEC translation, according to RSX-11M-PLUS and Micro/RSX */
/* I/O Drivers Reference manual - AA-JS11A-TC                  */
static const int o26_dec_code[] = {
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control  */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* chars    */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control  */
        ERROR,ERROR,07417,ERROR,ERROR,ERROR,ERROR,ERROR, /* chars    */
        00000,04006,01022,01102,02102,01006,02006,00012, /*  !"#$%&' */
        01042,04042,02042,04000,01102,02000,04102,01400, /* ()*+,-./ */
        01000,00400,00200,00100,00040,00020,00010,00004, /* 01234567 */
        00002,00001,02202,01202,04012,00102,02012,04202, /* 89:;<=>? */
        00042,04400,04200,04100,04040,04020,04010,04004, /* @ABCDEFG */
        04002,04001,02400,02200,02100,02040,02020,02010, /* HIJKLMNO */
        02004,02002,02001,01200,01100,01040,01020,01010, /* PQRSTUVW */
        01004,01002,01001,02022,00006,04022,00022,00202, /* XYZ[\]^_ */
        ERROR,04400,04200,04100,04040,04020,04010,04004, /* `abcdefg */
        04002,04001,02400,02200,02100,02040,02020,02010, /* hijklmno */
        02004,02002,02001,01200,01100,01040,01020,01010, /* pqrstuvw */
        01004,01002,01001,04000,ERROR,02000,ERROR,ERROR  /* xyz{|}~  */
    };

/* FULL EBCDIC, from Appendix C of System 360 Programming by Alex Thomas,
   1977, Reinhart Press, San Francisco.  Codes not in that table have been
   left compatable with DEC's 029 table.  Some control codes have been
   left out */
static const int EBCDIC_code[] = {
        05403,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control */
        02011,04021,01021,ERROR,04041,02021,ERROR,ERROR, /* chars   */
        ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR,ERROR, /* control */
        ERROR,ERROR,ERROR,ERROR,01201,ERROR,ERROR,ERROR, /* chars   */
        00000,02202,00006,00102,02102,01042,04000,00022, /*  !"#$%&' */
        04022,02022,02042,04012,01102,02000,04102,01400, /* ()*+,-./ */
        01000,00400,00200,00100,00040,00020,00010,00004, /* 01234567 */
        00002,00001,00202,02012,04042,00012,01012,01006, /* 89:;<=>? */
        00042,04400,04200,04100,04040,04020,04010,04004, /* @ABCDEFG */
        04002,04001,02400,02200,02100,02040,02020,02010, /* HIJKLMNO */
        02004,02002,02001,01200,01100,01040,01020,01010, /* PQRSTUVW */
        01004,01002,01001,04202,02006,01202,04006,01022, /* XYZ[\]^_ */
        ERROR,05400,05200,05100,05040,05020,05010,05004, /* `abcdefg */
        05002,05001,06400,06200,06100,06040,06020,06010, /* hijklmno */
        06004,06002,06001,03200,03100,03040,03020,03010, /* pqrstuvw */
        03004,03002,03001,ERROR,ERROR,ERROR,ERROR,ERROR  /* xyz{|}~  */
    };
/* DEC's 026 code extended to full 7-bit ASCII, as used in the DECsystem-10. */
static const int o26_decascii_code[] = {
        05403, 04401, 04201, 04101, 00005, 01023, 01013, 01007,
        02011, 04021, 01021, 04103, 04043, 04023, 04013, 04007,
        06403, 02401, 02201, 02101, 00043, 00023, 00201, 01011,
        02003, 02403, 00007, 01005, 02043, 02023, 02013, 02007,
        00000, 04006, 01022, 01012, 02102, 01006, 02006, 00012,
        01042, 04042, 02042, 04000, 01102, 02000, 04102, 01400,
        01000, 00400, 00200, 00100, 00040, 00020, 00010, 00004,
        00002, 00001, 02202, 01202, 04012, 00102, 02012, 04202,
        00042, 04400, 04200, 04100, 04040, 04020, 04010, 04004,
        04002, 04001, 02400, 02200, 02100, 02040, 02020, 02010,
        02004, 02002, 02001, 01200, 01100, 01040, 01020, 01010,
        01004, 01002, 01001, 02022, 00006, 04022, 00022, 00202,
        00402, 05400, 05200, 05100, 05040, 05020, 05010, 05004,
        05002, 05001, 06400, 06200, 06100, 06040, 06020, 06010,
        06004, 06002, 06001, 03200, 03100, 03040, 03020, 03010,
        03004, 03002, 03001, 05000, 06000, 03000, 03400, 04005,
};
/* DEC's 029 code extended to full 7-bit ASCII, as used in the DECsystem-10. */
static const int o29_decascii_code[] = {
        05403, 04401, 04201, 04101, 00005, 01023, 01013, 01007,
        02011, 04021, 01021, 04103, 04043, 04023, 04013, 04007,
        06403, 02401, 02201, 02101, 00043, 00023, 00201, 01011,
        02003, 02403, 00007, 01005, 02043, 02023, 02013, 02007,
        00000, 04006, 00006, 00102, 02102, 01042, 04000, 00022,
        04022, 02022, 02042, 04012, 01102, 02000, 04102, 01400,
        01000, 00400, 00200, 00100, 00040, 00020, 00010, 00004,
        00002, 00001, 00202, 02012, 04042, 00012, 01012, 01006,
        00042, 04400, 04200, 04100, 04040, 04020, 04010, 04004,
        04002, 04001, 02400, 02200, 02100, 02040, 02020, 02010,
        02004, 02002, 02001, 01200, 01100, 01040, 01020, 01010,
        01004, 01002, 01001, 04202, 01202, 02202, 02006, 01022,
        00402, 05400, 05200, 05100, 05040, 05020, 05010, 05004,
        05002, 05001, 06400, 06200, 06100, 06040, 06020, 06010,
        06004, 06002, 06001, 03200, 03100, 03040, 03020, 03010,
        03004, 03002, 03001, 05000, 06000, 03000, 03400, 04005,
};
static const int h2c_code[4096] = {
    0000, 0020, 0010, 0030, 0007, 0027, 0017, 0037,
    0006, 0026, 0016, 0036, 0007, 0027, 0017, 0037,
    0005, 0025, 0015, 0035, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0004, 0024, 0014, 0034, 0007, 0027, 0017, 0037,
    0006, 0026, 0016, 0036, 0007, 0027, 0017, 0037,
    0005, 0025, 0015, 0035, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0003, 0023, 0013, 0033, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0002, 0022, 0012, 0032, 0007, 0027, 0017, 0037,
    0006, 0026, 0016, 0036, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0006, 0026, 0016, 0036, 0007, 0027, 0017, 0037,
    0006, 0026, 0016, 0036, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0003, 0023, 0013, 0033, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0001, 0021, 0011, 0031, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0005, 0025, 0015, 0035, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0005, 0025, 0015, 0035, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0005, 0025, 0015, 0035, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0003, 0023, 0013, 0033, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0003, 0023, 0013, 0033, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0003, 0023, 0013, 0033, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0007, 0027, 0017, 0037, 0007, 0027, 0017, 0037,
    0040, 0060, 0050, 0070, 0047, 0067, 0057, 0077,
    0046, 0066, 0056, 0076, 0047, 0067, 0057, 0077,
    0045, 0065, 0055, 0075, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0044, 0064, 0054, 0074, 0047, 0067, 0057, 0077,
    0046, 0066, 0056, 0076, 0047, 0067, 0057, 0077,
    0045, 0065, 0055, 0075, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0043, 0063, 0053, 0073, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0042, 0062, 0052, 0072, 0047, 0067, 0057, 0077,
    0046, 0066, 0056, 0076, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0046, 0066, 0056, 0076, 0047, 0067, 0057, 0077,
    0046, 0066, 0056, 0076, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0043, 0063, 0053, 0073, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0041, 0061, 0051, 0071, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0045, 0065, 0055, 0075, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0045, 0065, 0055, 0075, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0045, 0065, 0055, 0075, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0043, 0063, 0053, 0073, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0043, 0063, 0053, 0073, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0043, 0063, 0053, 0073, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0047, 0067, 0057, 0077, 0047, 0067, 0057, 0077,
    0100, 0120, 0110, 0130, 0107, 0127, 0117, 0137,
    0106, 0126, 0116, 0136, 0107, 0127, 0117, 0137,
    0105, 0125, 0115, 0135, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0104, 0124, 0114, 0134, 0107, 0127, 0117, 0137,
    0106, 0126, 0116, 0136, 0107, 0127, 0117, 0137,
    0105, 0125, 0115, 0135, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0103, 0123, 0113, 0133, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0102, 0122, 0112, 0132, 0107, 0127, 0117, 0137,
    0106, 0126, 0116, 0136, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0106, 0126, 0116, 0136, 0107, 0127, 0117, 0137,
    0106, 0126, 0116, 0136, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0103, 0123, 0113, 0133, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0101, 0121, 0111, 0131, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0105, 0125, 0115, 0135, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0105, 0125, 0115, 0135, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0105, 0125, 0115, 0135, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0103, 0123, 0113, 0133, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0103, 0123, 0113, 0133, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0103, 0123, 0113, 0133, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0107, 0127, 0117, 0137, 0107, 0127, 0117, 0137,
    0140, 0160, 0150, 0170, 0147, 0167, 0157, 0177,
    0146, 0166, 0156, 0176, 0147, 0167, 0157, 0177,
    0145, 0165, 0155, 0175, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0144, 0164, 0154, 0174, 0147, 0167, 0157, 0177,
    0146, 0166, 0156, 0176, 0147, 0167, 0157, 0177,
    0145, 0165, 0155, 0175, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0143, 0163, 0153, 0173, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0142, 0162, 0152, 0172, 0147, 0167, 0157, 0177,
    0146, 0166, 0156, 0176, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0146, 0166, 0156, 0176, 0147, 0167, 0157, 0177,
    0146, 0166, 0156, 0176, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0143, 0163, 0153, 0173, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0141, 0161, 0151, 0171, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0145, 0165, 0155, 0175, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0145, 0165, 0155, 0175, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0145, 0165, 0155, 0175, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0143, 0163, 0153, 0173, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0143, 0163, 0153, 0173, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0143, 0163, 0153, 0173, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0147, 0167, 0157, 0177, 0147, 0167, 0157, 0177,
    0200, 0220, 0210, 0230, 0207, 0227, 0217, 0237,
    0206, 0226, 0216, 0236, 0207, 0227, 0217, 0237,
    0205, 0225, 0215, 0235, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0204, 0224, 0214, 0234, 0207, 0227, 0217, 0237,
    0206, 0226, 0216, 0236, 0207, 0227, 0217, 0237,
    0205, 0225, 0215, 0235, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0203, 0223, 0213, 0233, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0202, 0222, 0212, 0232, 0207, 0227, 0217, 0237,
    0206, 0226, 0216, 0236, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0206, 0226, 0216, 0236, 0207, 0227, 0217, 0237,
    0206, 0226, 0216, 0236, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0203, 0223, 0213, 0233, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0201, 0221, 0211, 0231, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0205, 0225, 0215, 0235, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0205, 0225, 0215, 0235, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0205, 0225, 0215, 0235, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0203, 0223, 0213, 0233, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0203, 0223, 0213, 0233, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0203, 0223, 0213, 0233, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0207, 0227, 0217, 0237, 0207, 0227, 0217, 0237,
    0240, 0260, 0250, 0270, 0247, 0267, 0257, 0277,
    0246, 0266, 0256, 0276, 0247, 0267, 0257, 0277,
    0245, 0265, 0255, 0275, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0244, 0264, 0254, 0274, 0247, 0267, 0257, 0277,
    0246, 0266, 0256, 0276, 0247, 0267, 0257, 0277,
    0245, 0265, 0255, 0275, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0243, 0263, 0253, 0273, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0242, 0262, 0252, 0272, 0247, 0267, 0257, 0277,
    0246, 0266, 0256, 0276, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0246, 0266, 0256, 0276, 0247, 0267, 0257, 0277,
    0246, 0266, 0256, 0276, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0243, 0263, 0253, 0273, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0241, 0261, 0251, 0271, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0245, 0265, 0255, 0275, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0245, 0265, 0255, 0275, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0245, 0265, 0255, 0275, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0243, 0263, 0253, 0273, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0243, 0263, 0253, 0273, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0243, 0263, 0253, 0273, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0247, 0267, 0257, 0277, 0247, 0267, 0257, 0277,
    0300, 0320, 0310, 0330, 0307, 0327, 0317, 0337,
    0306, 0326, 0316, 0336, 0307, 0327, 0317, 0337,
    0305, 0325, 0315, 0335, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0304, 0324, 0314, 0334, 0307, 0327, 0317, 0337,
    0306, 0326, 0316, 0336, 0307, 0327, 0317, 0337,
    0305, 0325, 0315, 0335, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0303, 0323, 0313, 0333, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0302, 0322, 0312, 0332, 0307, 0327, 0317, 0337,
    0306, 0326, 0316, 0336, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0306, 0326, 0316, 0336, 0307, 0327, 0317, 0337,
    0306, 0326, 0316, 0336, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0303, 0323, 0313, 0333, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0301, 0321, 0311, 0331, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0305, 0325, 0315, 0335, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0305, 0325, 0315, 0335, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0305, 0325, 0315, 0335, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0303, 0323, 0313, 0333, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0303, 0323, 0313, 0333, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0303, 0323, 0313, 0333, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0307, 0327, 0317, 0337, 0307, 0327, 0317, 0337,
    0340, 0360, 0350, 0370, 0347, 0367, 0357, 0377,
    0346, 0366, 0356, 0376, 0347, 0367, 0357, 0377,
    0345, 0365, 0355, 0375, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0344, 0364, 0354, 0374, 0347, 0367, 0357, 0377,
    0346, 0366, 0356, 0376, 0347, 0367, 0357, 0377,
    0345, 0365, 0355, 0375, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0343, 0363, 0353, 0373, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0342, 0362, 0352, 0372, 0347, 0367, 0357, 0377,
    0346, 0366, 0356, 0376, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0346, 0366, 0356, 0376, 0347, 0367, 0357, 0377,
    0346, 0366, 0356, 0376, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0343, 0363, 0353, 0373, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0341, 0361, 0351, 0371, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0345, 0365, 0355, 0375, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0345, 0365, 0355, 0375, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0345, 0365, 0355, 0375, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0343, 0363, 0353, 0373, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0343, 0363, 0353, 0373, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0343, 0363, 0353, 0373, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
    0347, 0367, 0357, 0377, 0347, 0367, 0357, 0377,
};
