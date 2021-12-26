//
// Created by oriya on 1/3/19.
//

#ifndef UNTITLED9_CACHEMANAGER_H
#define UNTITLED9_CACHEMANAGER_H

template<class Problem, class Solution>
class CacheManager {
public:
    virtual void save(Problem* problem,Solution* soulution) = 0;

    virtual bool isProblemExist(Problem* problem)=0;

    virtual Solution* search(Problem* problem) = 0;
};

#endif //UNTITLED9_CACHEMANAGER_H
