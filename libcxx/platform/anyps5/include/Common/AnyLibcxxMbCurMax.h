#ifndef ANYLIBCXX_MB_CUR_MAX_H
#define ANYLIBCXX_MB_CUR_MAX_H
#ifdef __cplusplus
extern "C" {
#endif
int AnyLibcxxMbCurMax(void);
#ifdef __cplusplus
}
#endif
#undef MB_CUR_MAX
#define MB_CUR_MAX AnyLibcxxMbCurMax()
#endif
