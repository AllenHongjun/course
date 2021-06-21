vbc /t:library /out:Interop1.dll Interop1.vb
jsc /t:library /out:Interop2.dll Interop2.js
csc /t:exe /out:Interop3.exe /r:Interop1.dll /r:Interop2.dll /r:Microsoft.JScript.dll Interop3.cs
