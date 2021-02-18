//
// Created by 竺冰 on 2021/2/16.
//

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/MD5.h"

using namespace llvm;
namespace {
    struct OutEncryptFunctionName : public FunctionPass {
        static char ID;
        OutEncryptFunctionName() : FunctionPass(ID) {}

        bool runOnFunction(Function &F) override {
            if (F.getName().compare("main") != 0) {
                MD5 Hash;
                Hash.update(F.getName());
                MD5::MD5Result MD5Res;
                Hash.final(MD5Res);
                SmallString<32> Res;
                MD5::stringifyResult(MD5Res, Res);
                errs() << F.getName() + " is encrypted to " + Res << "\r\n";
                F.setName(Res);
            }
            return false;
        }
    };
}

char OutEncryptFunctionName::ID = 0;
static RegisterPass<OutEncryptFunctionName> X("oefn", "encrypt function name with MD5",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);