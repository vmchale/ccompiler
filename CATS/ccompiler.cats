// see:
// http://nadeausoftware.com/articles/2012/10/c_c_tip_how_detect_compiler_name_and_version_using_compiler_predefined_macros#Howtodetectthecompilerversion

#if defined(__clang__)
void print_compiler_version(void) {
  printf("compiled with clang version: %d.%d.%d\n", __clang_major__,
         __clang_minor__, __clang_patchlevel__);
}
#elif defined(__GNUC__)
void print_compiler_version(void) {
  printf("compiled with gcc version: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__,
         __GNUC_PATCHLEVEL__);
}
#elif defined(__INTEL_COMPILER)
void print_compiler_version(void) {
  int icc_major;
  int icc_minor;
  icc_major = __INTEL_COMPILER / 100;
  icc_minor = __INTEL_COMPILER % 100;

  printf("compiled with icc version: %d.%d\n", icc_major, icc_minor);
}
#elif defined(__PGIC__)
void print_compiler_version(void) {
  prinf("compiled with pgcc version: %d.%d\n", __PGIC__,
        __PGIC_PATCHLEVEL__);
}
#else
void print_compiler_version(void) {}
#endif
