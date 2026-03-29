# libpcm8a
PCM8A - C bridge library for X68k

elf2x68k環境向けのPCM8AドライバのファンクションコールラッパーCライブラリです。

PCM8Aのファンクションコールに準じた以下の関数が利用可能です。MPCMファンクションコールは対応していません。
```
#include <pcm8a.h>

int32_t pcm8a_play(int16_t channel, uint32_t mode, size_t size, void* addr);
int32_t pcm8a_play_array_chain(int16_t channel, uint32_t mode, size_t count, void* addr);
int32_t pcm8a_play_linked_array_chain(int16_t channel, uint32_t mode, void* addr);
int32_t pcm8a_set_channel_mode(int16_t channel, uint32_t mode);
int32_t pcm8a_get_data_length(int16_t channel);
int32_t pcm8a_get_channel_mode(int16_t channel);
void* pcm8a_get_access_address(int16_t channel);
int32_t pcm8a_stop();
int32_t pcm8a_pause();
int32_t pcm8a_resume();
int32_t pcm8a_set_system_information(uint32_t sys_info);
int32_t pcm8a_set_polyphonic_mode(int16_t mode);
```

また、PCM8Aの常駐確認を行う関数も利用可能です。
```
int32_t pcm8a_isavailable();
```


使う時は、サブモジュールとして組み込むのが簡単です。例えばプロジェクト直下にて以下を実行します。

```
git submodule add https://github.com/tantanGH/libpcm8a.git libs/libpcm8a
```

以下のようなツリーとなります。

```
my_app/
├── .git/
├── .gitmodules
├── libs/
│   └── libpcm8a/
│       ├── include/pcm8a.h
│       └── lib/libpcm8a.a
└── src/
    ├── main.c
    └── Makefile
```

ヘッダー検索パスとライブラリ検索パスをMakefile内で
```
-I../libs/libpcm8a/include
-L../libs/libpcm8a/lib
```
のように指定し、`-ldos -liocs -lpcm8a` でリンクできます。
内部的にDOSコールとIOCSコールを使っているため、`-ldos -liocs`もリンクしてください。