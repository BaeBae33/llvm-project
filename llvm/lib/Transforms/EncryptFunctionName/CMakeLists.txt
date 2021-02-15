add_llvm_library( LLVMEncryptFunctionName MODULE
        EncryptFunctionName.cpp

        PLUGIN_TOOL
        opt
        )