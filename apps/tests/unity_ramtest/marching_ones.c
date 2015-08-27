/****************************************************************************
 * apps/tests/unity_ramtest/marching_ones.c
 * Automated RAM test copied from apps/system/ramtest
 *
 *   Copyright (C) 2015 Haltian Ltd. All rights reserved.
 *   Author: Roman Saveljev <roman.saveljev@haltian.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <nuttx/testing/unity_fixture.h>
#include "library.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Private Data
 ****************************************************************************/
static void* g_memory;

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/
static void marching_ones(enum memory_access_width width, uint32_t mask)
{
  uint32_t pattern = 0x00000001;

  while (pattern != 0)
    {
      unity_ramtest_write_memory(pattern, width, g_memory, MEMORY_ALLOCATION_SIZE);
      unity_ramtest_verify_memory(pattern, width, g_memory, MEMORY_ALLOCATION_SIZE);
      pattern <<= 1;
      pattern &= mask;
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

TEST_GROUP(MarchingOnes);

/****************************************************************************
 * Name: MarchingOnes test group setup
 *
 * Description:
 *   Setup function executed before each testcase in this test group
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 * Assumptions/Limitations:
 *   None
 *
 ****************************************************************************/
TEST_SETUP(MarchingOnes)
{
  g_memory = malloc(MEMORY_ALLOCATION_SIZE);
  TEST_ASSERT_NOT_NULL(g_memory);
}

/****************************************************************************
 * Name: MarchingOnes test group tear down
 *
 * Description:
 *   Tear down function executed after each testcase in this test group
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 * Assumptions/Limitations:
 *   None
 *
 ****************************************************************************/
TEST_TEAR_DOWN(MarchingOnes)
{
  free(g_memory);
  g_memory = NULL;
}

/****************************************************************************
 * Name: ByteAccess
 *
 * Description:
 *   Running one on every memory location with byte access width
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 * Assumptions/Limitations:
 *   None
 *
 ****************************************************************************/
TEST(MarchingOnes, ByteAccess)
{
  marching_ones(MEMORY_ACCESS_BYTE, 0xff);
}

/****************************************************************************
 * Name: HalfAccess
 *
 * Description:
 *   Running one on every memory location with half-word access width
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 * Assumptions/Limitations:
 *   None
 *
 ****************************************************************************/
TEST(MarchingOnes, HalfAccess)
{
  marching_ones(MEMORY_ACCESS_HALFWORD, 0xffff);
}

/****************************************************************************
 * Name: WordAccess
 *
 * Description:
 *   Running one on every memory location with word access width
 *
 * Input Parameters:
 *   None
 *
 * Returned Value:
 *   None
 *
 * Assumptions/Limitations:
 *   None
 *
 ****************************************************************************/
TEST(MarchingOnes, WordAccess)
{
  marching_ones(MEMORY_ACCESS_WORD, 0xffffffff);
}
