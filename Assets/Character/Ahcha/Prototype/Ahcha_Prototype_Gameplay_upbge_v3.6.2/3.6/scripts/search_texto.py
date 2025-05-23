import os

def search_text_in_files(directory, text):
    found_files = []
    # Percorre todos os diretórios e arquivos dentro do diretório atual
    for root, dirs, files in os.walk(directory):
        for file in files:
            # Verifica se o arquivo é um arquivo Python (.py)
            if file.endswith('.py'):
                # Cria o caminho completo para o arquivo
                file_path = os.path.join(root, file)

                if not 'lf_env' in file_path:
                    print("Pesquisando em:", file_path)
                    try:
                        # Abre o arquivo e lê seu conteúdo
                        with open(file_path, 'r', encoding='utf-8') as f:
                            file_content = f.read()
                        # Verifica se o texto está presente no conteúdo do arquivo
                        if text in file_content:
                            found_files.append(file_path)
                    except Exception as e:
                        print(f"Erro ao ler o arquivo {file_path}: {e}")
                
    return found_files

# Diretório onde o script Python está localizado
diretorio = os.path.dirname(os.path.abspath(__file__))
# Texto a ser pesquisado nos arquivos
texto_pesquisa = "ReloadAllComponentsOperator"
print(f'\n\ntexto a pesquisar: {texto_pesquisa}')

# Realiza a pesquisa
arquivos_encontrados = search_text_in_files(diretorio, texto_pesquisa)

# Exibe os arquivos encontrados
if arquivos_encontrados:
    print("Os seguintes arquivos contêm o texto pesquisado:")
    for arquivo in arquivos_encontrados:
        print(arquivo)
else:
    print("Nenhum arquivo encontrado com o texto pesquisado.")
