//lucia fuentes
#pragma once

#include "sampleGenerator.h"

class CSampleGeneratorRegular : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE
        
        int total = 0, x = 0, y = 0;
        for (x; i < sqrt(n); x++) {
            for (y; y < sqrt(n); y++) {
                v[total] = (y + 0.5f) / sqrt(n);
                u[total] = (x + 0.5f) / sqrt(n);
        
                weight[total] = 1.0(float) / n;
                
                total = total + 1;
            }
        }
	}
};
