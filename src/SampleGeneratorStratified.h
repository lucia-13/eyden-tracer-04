//lucia fuentes
#pragma once

#include "sampleGenerator.h"

class CSampleGeneratorStratified : public CSampleGenerator
{
public:
	virtual void getSamples(int n, float* u, float* v, float* weight) const override
	{
		// --- PUT YOUR CODE HERE -
        int total = 0, x = 0, y = 0;
        for (x; x < sqrt(n); x++) {
            for (y; y < sqrt(n); y++) {
                float strX = DirectGraphicalModels::random::U<float>();
                float strY = DirectGraphicalModels::random::U<float>();
                    v[total] = (y + strY) / sqrt(n);
                u[total] = (x + strX) / sqrt(n);
                weight[total] = 1.0(float) / n;
               
                total = total + 1;
            }
        }
	}
};
