//lucia fuentes
#include "Scene.h"

#include "ShaderEyelight.h"
#include "ShaderEyelightTextured.h"
#include "ShaderPhong.h"
#include "PrimTriangle.h"
#include "PrimTriangleSmooth.h"
#include "PrimTriangleSmoothTextured.h"

#include <fstream> 


void CScene::ParseOBJ(const std::string& fileName)
{
	std::ifstream file(fileName);

	if (file.is_open()) {
		std::cout << "Parsing OBJFile : " << fileName << std::endl;

		std::shared_ptr<IShader> pShader = std::make_shared<CShaderEyelight>(RGB(1, 0.5f, 0));
		std::vector<Vec3f> vVertexes;
		std::vector<Vec2f> v_text;
        
        std::vector<Vec3f> v_n;
		std::string line;

		for (;;) {
			if (!getline(file, line)) break;
			std::stringstream ss(line);
			getline(ss, line, ' ');
			if (line == "v") {
				Vec3f v;
				for (int i = 0; i < 3; i++) ss >> v.val[i];
				// std::cout << "Vertex: " << v << std::endl;
				vVertexes.emplace_back(100 * v);
			}
            else if (line == "vt") {
                        Vec2f tt;
                int y = 0;
                        for (y; y < 2; y++) ss >> tt.val[y];
                    v_text.emplace_back(100 * tt);
                    }
                    else if (line == "vn") {
                        Vec3f nn;
                        int x = 0;
                        for (x; x < 2; x++) ss >> nn.val[x];
                    v_n.emplace_back(100 * nn);
                    }
			else if (line == "f") {
				Vec3i f;
				for (int i = 0; i < 3; i++) ss >> f.val[i];
				// std::cout << "Face: " << f << std::endl;
				Add(std::make_shared<CPrimTriangle>(vVertexes[f.val[0] - 1], vVertexes[f.val[1] - 1], vVertexes[f.val[2] - 1], pShader));
			}
			else {
				std::cout << "Unknown key [" << line << "] met in the OBJ file" << std::endl;
			}
		}

		file.close();
		std::cout << "Finished Parsing" << std::endl;
	} else
		std::cout << "ERROR: Can't open OBJFile" << std::endl;
}
