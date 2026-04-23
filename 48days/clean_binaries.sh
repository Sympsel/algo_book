#!/bin/bash
# clean_binaries.sh - 递归删除二进制文件，保留 .git 目录

echo "🔍 正在查找需要删除的二进制文件..."

echo "📋 将要删除的文件列表："
echo "----------------------------------------"

# 查找并显示将要删除的文件（预览）
find . -type f \( \
    -name "*.exe" -o \
    -name "*.out" -o \
    -name "*.o" -o \
    -name "*.obj" -o \
    -name "*.so" -o \
    -name "*.dll" -o \
    -name "*.a" -o \
    -name "*.lib" \
\) ! -path "./.git/*" -print

# 查找无扩展名的可执行文件（ELF），排除 .git 和脚本
find . -type f ! -path "./.git/*" ! -name "*.*" -executable -print 2>/dev/null | while read f; do
    if file "$f" | grep -q "ELF\|executable\|PE32"; then
        echo "$f"
    fi
done

echo "----------------------------------------"
read -p "⚠️  确认删除以上文件吗？(Y/N): " confirm

if [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]]; then
    echo "🗑️  正在删除..."
    
    # 删除有扩展名的二进制文件
    find . -type f \( \
        -name "*.exe" -o \
        -name "*.out" -o \
        -name "*.o" -o \
        -name "*.obj" -o \
        -name "*.so" -o \
        -name "*.dll" -o \
        -name "*.a" -o \
        -name "*.lib" \
    \) ! -path "./.git/*" -delete
    
    # 删除无扩展名的 ELF 可执行文件
    find . -type f ! -path "./.git/*" ! -name "*.*" -executable 2>/dev/null | while read f; do
        if file "$f" | grep -q "ELF\|executable\|PE32"; then
            rm -f "$f"
            echo "  已删除: $f"
        fi
    done
    
    echo "✅ 清理完成！"
else
    echo "❌ 已取消操作"
fi
