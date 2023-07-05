#!/bin/bash
grep -E "theo1|steven1|arnaud1|pierre-jean" | grep -E "theo1|steven1|arnaud1|pierre-jean" | sed -e 's/theo1/Wile E. Coyote/; s/steven1/Daffy Duck/; s/arnaud1/Porky Pig/; s/pierre-jean/Marvin the Martian/'
