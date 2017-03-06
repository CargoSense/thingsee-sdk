//- Copyright (c) 2010 James Grenning and Contributed to Unity Project
/* ==========================================
    Unity Project - A Test Framework for C
    Copyright (c) 2007 Mike Karlesky, Mark VanderVoord, Greg Williams
    [Released under MIT License. Please refer to license.txt for details]
========================================== */

#include <apps/testing/unity_fixture.h>

TEST_GROUP_RUNNER(UnityFixture)
{
    RUN_TEST_CASE(UnityFixture, PointerSetting);
    RUN_TEST_CASE(UnityFixture, ForceMallocFail);
    RUN_TEST_CASE(UnityFixture, ReallocSmallerIsUnchanged);
    RUN_TEST_CASE(UnityFixture, ReallocSameIsUnchanged);
    RUN_TEST_CASE(UnityFixture, ReallocLargerNeeded);
    RUN_TEST_CASE(UnityFixture, ReallocNullPointerIsLikeMalloc);
    RUN_TEST_CASE(UnityFixture, ReallocSizeZeroFreesMemAndReturnsNullPointer);
    RUN_TEST_CASE(UnityFixture, CallocFillsWithZero);
    RUN_TEST_CASE(UnityFixture, PointerSet);
}

TEST_GROUP_RUNNER(UnityCommandOptions)
{
    RUN_TEST_CASE(UnityCommandOptions, DefaultOptions);
    RUN_TEST_CASE(UnityCommandOptions, OptionVerbose);
    RUN_TEST_CASE(UnityCommandOptions, OptionSelectTestByGroup);
    RUN_TEST_CASE(UnityCommandOptions, OptionSelectTestByName);
    RUN_TEST_CASE(UnityCommandOptions, OptionSelectRepeatTestsDefaultCount);
    RUN_TEST_CASE(UnityCommandOptions, OptionSelectRepeatTestsSpecificCount);
    RUN_TEST_CASE(UnityCommandOptions, MultipleOptions);
    RUN_TEST_CASE(UnityCommandOptions, MultipleOptionsDashRNotLastAndNoValueSpecified);
    RUN_TEST_CASE(UnityCommandOptions, UnknownCommandIsIgnored);
    RUN_TEST_CASE(UnityCommandOptions, Listing);
    RUN_TEST_CASE(UnityCommandOptions, ExactList);
}

TEST_GROUP_RUNNER(LeakDetection)
{
    RUN_TEST_CASE(LeakDetection, DetectsLeak);
    RUN_TEST_CASE(LeakDetection, BufferOverrunFoundDuringFree);
    RUN_TEST_CASE(LeakDetection, BufferOverrunFoundDuringRealloc);
}

TEST_GROUP_RUNNER(Timeout)
{
    RUN_TEST_CASE(Timeout, Triggers);
    RUN_TEST_CASE(Timeout, DoesNotTrigger);
}

TEST_GROUP_RUNNER(TimeoutInSetup)
{
    RUN_TEST_CASE(TimeoutInSetup, Test);
}

TEST_GROUP_RUNNER(TimeoutInBody)
{
    RUN_TEST_CASE(TimeoutInBody, Test);
}

TEST_GROUP_RUNNER(TimeoutInTearDown)
{
    RUN_TEST_CASE(TimeoutInTearDown, Test);
}
