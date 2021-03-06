/* Copyright (c) 2021 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#ifndef EXECUTOR_QUERY_INNERJOINEXECUTOR_H_
#define EXECUTOR_QUERY_INNERJOINEXECUTOR_H_

#include "executor/query/JoinExecutor.h"

namespace nebula {
namespace graph {

class InnerJoinExecutor final : public JoinExecutor {
public:
    InnerJoinExecutor(const PlanNode* node, QueryContext* qctx)
        : JoinExecutor("InnerJoinExecutor", node, qctx) {}

    folly::Future<Status> execute() override;

    Status close() override;

private:
    folly::Future<Status> join();
    DataSet probe(const std::vector<Expression*>& probeKeys, Iterator* probeiter);

private:
    bool exchange_{false};
};
}  // namespace graph
}  // namespace nebula
#endif
