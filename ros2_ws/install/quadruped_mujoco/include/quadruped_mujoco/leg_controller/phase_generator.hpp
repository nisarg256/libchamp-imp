#ifndef PHASE_GENERATOR_HPP
#define PHASE_GENERATOR_HPP

#include "quadruped_mujoco/macros/macros.h"
#include "quadruped_mujoco/quadruped_base/quadruped_base.hpp"

namespace champ
{
    class PhaseGenerator
    {
        public:
            typedef unsigned long int Time;
            static inline Time now() { return time_us(); }

            float stance_phase_signal[4];
            float swing_phase_signal[4];
            bool has_started;

            PhaseGenerator(QuadrupedBase &base, Time time = now()):
                base_(&base),
                last_touchdown_(time),
                has_swung_(false),
                has_started(false)
            {
                for(unsigned int i = 0; i < 4; i++)
                {
                    stance_phase_signal[i] = 0.0f;
                    swing_phase_signal[i] = 0.0f;
                }
            }

            void run(float target_velocity, float step_length, Time time = now())
            {
                float stance_phase_period = base_->gait_config_.stance_duration * SECONDS_TO_MICROS;
                float swing_phase_period = 0.25f * SECONDS_TO_MICROS;
                float stride_period = stance_phase_period + swing_phase_period;
                float elapsed_time_ref = 0;

                elapsed_time_ref = time - last_touchdown_;
                if(elapsed_time_ref > stride_period)
                {
                    last_touchdown_ = time;
                    elapsed_time_ref = 0;
                }

                for(unsigned int i = 0; i < 4; i++)
                {
                    if(elapsed_time_ref < stance_phase_period)
                    {
                        stance_phase_signal[i] = elapsed_time_ref / stance_phase_period;
                        swing_phase_signal[i] = 0.0f;
                    }
                    else
                    {
                        swing_phase_signal[i] = (elapsed_time_ref - stance_phase_period) / swing_phase_period;
                        stance_phase_signal[i] = 0.0f;
                    }
                }
            }

        private:
            QuadrupedBase *base_;
            Time last_touchdown_;
            bool has_swung_;
    };
}

#endif 