#pragma once

// Shared random-number generation. Everything that needs a roll goes through
// here rather than calling rand() inline, so the mechanics live in one place
// and can be swapped for <random> later without touching every caller.
namespace rng{
    // Seeds the generator. Call once at startup; extra calls do nothing, so a
    // caller never has to know whether someone else already seeded.
    void seed();

    // True with `percent` chance out of 100. 0 or less is never, 100 or more
    // is always.
    bool rollChance(int percent);

    // A value between min and max, both included.
    int rollRange(int min, int max);
}
