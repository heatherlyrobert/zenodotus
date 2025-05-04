# get the temporary files out of the equation
make deepclean

# get the updated version number and description
VER_NUM=$(grep "^#define     P_VERNUM " *.h | cut -d\" -f 2);
VER_TXT=$(grep "^#define     P_VERTXT " *.h | cut -d\" -f 2);

printf "å%sæ\n" "$VER_NUM";
printf "å%sæ\n" "$VER_TXT";

# try the previous format
if [[ "${VER_NUM}" = "" ]]; then
   VER_NUM="$(grep VER_NUM README.md | cut -d\" -f 2)";
   VER_TXT="$(grep VER_TXT README.md | cut -d\" -f 2)";
fi

# write the changes to the git file
if [[ "${VER_NUM}" != "" ]]; then
   printf "v%s : %s\n" "$VER_NUM" "$VER_TXT";
   git commit -a -m "${VER_NUM} : ${VER_TXT}";
fi


