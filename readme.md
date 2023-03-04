# Summary
GDExtension binding for the flecs ECS library. Provides simple gdscript bindings for rapid prototyping and a convenient starter project adding c++ ECS game code if needed.

# Setup
## gdscript
All that is needed to use the bindings from gdscript are the GDExtension dlls. If that is all that is needed (and it can take you quite far), you're done!

## c++
#### Dependencies
- Clone the project recursivly, godot-cpp is included as a submodule
- more steps soon (tm)

#### Debugging with VSCode and lldb
- install the CodeLLDB extension
- add something similar to this launch.json

    `{
        "version": "0.2.0",
        "configurations": [{
            "name": "Launch",
            "type": "lldb",
            "request": "launch",
            "program": "${workspaceRoot}/Godot_v4.0-stable_win64.exe",
            "args": ["--path", "test"],
            "cwd": "${workspaceFolder}",
        }]
    }`
    
    - this expects a godot editor to be in the root directory, but it can be pulled in from anywhere and 'program' modified accordingly.