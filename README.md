# pareto-optimality-house-allocation

### First stage: 
   Using Hopcroft-Karp, find the maximum matching $M$ given $G$. Running time is $O(\sqrt{n}m)$ and guarantees we find a maximal matching. 


### Second stage:

   Transform $M$ into a trade-in-free matching. In an iterative manner, free a house by breaking an assignment---driven by matching an agent's preference. Keep in mind this preference is yet another unmatched house. 
