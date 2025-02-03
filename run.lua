local function build_debug()
    print("\x1b[33mDebug\x1b[0m")
    os.execute("cmake --build build/debug")
end

local function build_release()
    print("\x1b[33mRelease\x1b[0m")
    return os.execute("cmake --build build/release --parallel 8")
end

local function build()
    print("\x1b[34mBuilding with GCC\x1b[0m")
    build_debug()
    build_release()
end

local function build_msvc()
    print("\x1b[34mBuilding with MSVC\x1b[0m")
    print("\x1b[33mDebug\x1b[0m")
    os.execute("cmake --build build/msvc --config Debug")
    print("\x1b[33mRelease\x1b[0m")
    os.execute("cmake --build build/msvc --config Release")
end

if arg[1] == 'gen' then
    print("\x1b[34mGenerating CMake files\x1b[0m")
    print("\x1b[33mMinGW Debug\x1b[0m")
    os.execute(
        "cmake -B build/debug . -G \"MinGW Makefiles\" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc")
    print("\x1b[33mMinGW Release\x1b[0m")
    os.execute(
        "cmake -B build/release . -G \"MinGW Makefiles\" -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc")
    print("\x1b[33mMSVC\x1b[0m")
    os.execute("cmake -B build/msvc .")
elseif arg[1] == 'build' then
    build_debug()
elseif arg[1] == 'msvc' then
    build_msvc()
elseif arg[1] == 'debug' then
    print("\x1b[34mBuilding Debug with GCC\x1b[0m")
    build_debug()
else
    print("\x1b[34mBuilding Release with GCC\x1b[0m")
    local res = build_release()
    if res == 0 then
        print("\x1b[33mRunning\x1b[0m")
        os.execute(".\\pec " .. (arg[1] or ""))
    end
end
