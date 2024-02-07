import style from './UserSectionSelectPage.module.css'
import { useNavigate } from "react-router-dom"

const UserSectionSelectPage = () => {
  const navigate = useNavigate();

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          Доступные тесты
        </div>
        <div className={style.imageBox}>
          <div>
            <img src="edu.png" alt="Education.png" onClick={ ()=>navigate('/user-subsection-select')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-subsection-select')}> Education (x)</div>
          </div>
          <div>
            <img src="psyho.png" alt="Psychological.png" onClick={ ()=>navigate('/user-subsection-select')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-subsection-select')}>Psychological (y)</div>
          </div>
          <div>
            <img src="funny.png" alt="Funny.png" onClick={ ()=>navigate('/user-subsection-select')}/>
            <div className={style.imageCaption} onClick={ ()=>navigate('/user-subsection-select')}>Funny (z)</div>
          </div>
        </div>
      </div>
  );
}

export default UserSectionSelectPage;
