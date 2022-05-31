
STLoadDataps.dll: dlldata.obj STLoadData_p.obj STLoadData_i.obj
	link /dll /out:STLoadDataps.dll /def:STLoadDataps.def /entry:DllMain dlldata.obj STLoadData_p.obj STLoadData_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del STLoadDataps.dll
	@del STLoadDataps.lib
	@del STLoadDataps.exp
	@del dlldata.obj
	@del STLoadData_p.obj
	@del STLoadData_i.obj
