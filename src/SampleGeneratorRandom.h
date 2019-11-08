//lucia fuentes
#pragma once

#include "sampleGenerator.h"

class CSampleGeneratorRandom : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE ---
        
        //added code
        int x = 0;
        for (x; x < n; x++) {
            u[x] = DirectGraphicalModels::random::U<float>();
            
            v[x] = DirectGraphicalModels::random::U<float>();
            
            weight[x] = 1.0(float) / n;
        }
	}
};


