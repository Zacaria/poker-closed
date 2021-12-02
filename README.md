# Poker game implemented using C++

# VSCode configuration

launch.json
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Broooo",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "lldb",
      "preLaunchTask": "clang++ build active file"
    }
  ]
}
```

tasks.json
```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "clang++ build active file",
      "command": "/usr/bin/clang++",
      "args": [
        "-std=c++17",
        "-stdlib=libc++",
        "-g",
        "${workspaceFolder}/*.cpp",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}"
      ],
      "options": {
        "cwd": "${workspaceFolder}"
      },
      "problemMatcher": {
          "base": "$gcc",
          "fileLocation":"absolute"
      },
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```