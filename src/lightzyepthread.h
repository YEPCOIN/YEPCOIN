// Copyright (c) 2015-2019 The PIVX developers
// Copyright (c) 2020 The YEP developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
//

#ifndef YEP_LIGHTZYEPTHREAD_H
#define YEP_LIGHTZYEPTHREAD_H

#include <atomic>
#include "genwit.h"
#include "zyep/accumulators.h"
#include "concurrentqueue.h"
#include "chainparams.h"
#include <boost/function.hpp>
#include <boost/thread.hpp>

extern CChain chainActive;
// Max amount of computation for a single request
const int COMP_MAX_AMOUNT = 60 * 24 * 60;


/****** Thread ********/

class CLightWorker{

private:

    concurrentqueue<CGenWit> requestsQueue;
    std::atomic<bool> isWorkerRunning;
    boost::thread threadIns;

public:

    CLightWorker() {
        isWorkerRunning = false;
    }

    enum ERROR_CODES {
        NOT_ENOUGH_MINTS = 0,
        NON_DETERMINED = 1
    };

    bool addWitWork(CGenWit wit) {
        if (!isWorkerRunning) {
            LogPrintf("%s not running trying to add wit work \n", "yep-light-thread");
            return false;
        }
        requestsQueue.push(wit);
        return true;
    }

    void StartLightZyepThread(boost::thread_group& threadGroup) {
        LogPrintf("%s thread start\n", "yep-light-thread");
        threadIns = boost::thread(boost::bind(&CLightWorker::ThreadLightZYEPSimplified, this));
    }

    void StopLightZyepThread() {
        threadIns.interrupt();
        LogPrintf("%s thread interrupted\n", "yep-light-thread");
    }

private:

    void ThreadLightZYEPSimplified();

    void rejectWork(CGenWit& wit, int blockHeight, uint32_t errorNumber);

};

#endif //YEP_LIGHTZYEPTHREAD_H
