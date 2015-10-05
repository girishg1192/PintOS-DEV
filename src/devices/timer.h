#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>
#include "threads/synch.h"
#include "threads/malloc.h"
/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

/* Sleep and yield the CPU to other threads. */
void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

// Block waiting thread for sleep
void thread_sleep(int64_t wakeTime);
void wake_sleeping ();

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

// Avoiding Busy Waits
//
struct wait_list
{
  struct semaphore sema;
  struct list_elem elem;
  int value;
};
struct lock critical;

void timer_print_stats (void);

#endif /* devices/timer.h */
