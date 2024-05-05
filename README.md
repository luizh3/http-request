### Descrição

Projeto genérico que exporta funcionalidades para fazer requests, construído com QT e C++

### Tecnologias 

<div style="display: inline_block">
	<img alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
	<img align="center" alt="QT" src="https://img.shields.io/badge/QT-00ff00?style=for-the-badge&logoColor=white" />
	<img align="center" alt="QT" src="https://img.shields.io/badge/QMAKE-0f246b?style=for-the-badge&logoColor=white" />
</div>

### Como usar ?

Necessario adicionar o `INCLUDEPATH` e `LIBS` no `.pro` do projeto que vai consumir a biblioteca.

Exemplo: [Dependencies]( https://github.com/luizh3/film-flow-core/blob/main/film-flow-core-dependencies.pri )

##### Metodos acessiveis 

- <b>Get</b>
```C++
	# Response precisar herdar de HttpStubResponse, implemetar metodo fromJson
	std::unique_ptr<Response> response( HttpRequestManager().get<Response>( URL,  requestParams ) )
```
Para exemplos mais detalhados consulte [film-flow-core-network](https://github.com/luizh3/film-flow-core/blob/main/network/endpoint/program/tvmaze/tvmazeendpoint.cpp)

### Dependências

| Name | versão | Fonte |
| ------ | ------ |  ------ |
| OpenSSL | 1.1.1 | https://slproweb.com/products/Win32OpenSSL.html |

