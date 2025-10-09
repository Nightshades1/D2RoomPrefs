import pefile,argparse,os,sys
parser = argparse.ArgumentParser(os.path.basename(sys.argv[0]),description="Tool to generate proxy dll")
parser.add_argument('--path',help="The path to the dll to be proxied")
args = parser.parse_args()

if(os.path.exists(args.path)):
    ProxyName = str(os.path.basename(args.path)).split(".")[0] + "_orig"
    pe = pefile.PE(args.path)
    with open("ProxyHeader.h","wt") as ProxyHeader:
            for entry in pe.DIRECTORY_ENTRY_EXPORT.symbols:
                name = entry.name.decode("utf-8")
                ProxyHeader.write(f"#pragma comment(linker, \"/export:{name}={ProxyName}.{name}\")\n")
                pass
            pass
    pass