// OTUS C++ basic course homework.
// ASTNode

#pragma once

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

class ASTNode {
  public:
    explicit ASTNode(const std::string &repr);

    ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs);

    ASTNode(const ASTNode &other) = delete;

    ASTNode &operator=(const ASTNode &other) = delete;

    ~ASTNode();

    std::string repr() const { return repr_; }
    void push_vector(ASTNode* _delete){delete_.push_back(_delete);}
    void print(std::ostream &out) const;
    void free_();

  private:
    void inner_print(std::ostream &out, size_t indent) const;
    std::vector<ASTNode*> delete_;
    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;
};


class Add : public ASTNode {
public:
    Add(ASTNode *lhs, ASTNode *rhs):
        ASTNode("+", lhs, rhs)
    {
    }
private:
};

//==================================================================
class Sub : public ASTNode {
public:
    Sub(ASTNode *lhs, ASTNode *rhs):
        ASTNode("-", lhs, rhs)
    {
    }
private:
};
//==================================================================
class Mul : public ASTNode {
public:
    Mul(ASTNode *lhs, ASTNode *rhs):
        ASTNode("*", lhs, rhs)
    {
    }
private:
};

//==================================================================
class Div : public ASTNode {
public:
    Div(ASTNode *lhs, ASTNode *rhs):
        ASTNode("/", lhs, rhs)
    {
    }
private:
};

