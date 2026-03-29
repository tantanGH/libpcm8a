#ifndef __H_PCM8A__
#define __H_PCM8A__

#include <stdint.h>
#include <stddef.h>

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
int32_t pcm8a_isavailable();

#endif